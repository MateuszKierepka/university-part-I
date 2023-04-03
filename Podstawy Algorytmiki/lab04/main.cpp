#include <iostream>
#include <fstream>
#include <sstream>

using  namespace std;

struct  student{
    string imie;
    string nazwisko;
    int l_p;
};

void wczytajStudentow(student*&tab, int n){
    tab = new student[n];
}

void usunTabliceStudentow(student *&tab){
    delete [] tab;
}

void wyswietlStudentow(student* tab, int n){
    for(int i=0; i<n; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<endl;
}

void wyswietlStudentowP(student* tab, int n, int p){
    cout<<"Studenci, ktorzy otrzymali <=10 punktow: "<<endl;
    for(int i=0; i<p; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<"Studenci, ktorzy otrzymali >10 punktow:"<<endl;
    for(int i=p; i<n; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<endl;
}

void wyswietlStudentowP2(student* tab, int n, int p, int g){
    cout<<"Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 :"<<endl;
    for(int i=0; i<=p; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<"Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1 :"<<endl;
    for(int i=p+1; i<g; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<"Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2 :"<<endl;
    for(int i=g; i<n; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
    cout<<endl;
}

int wczytywanieDanych(student*& tab){
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka="C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab04\\studenci.csv";
    plik.open(sciezka);
    if(!plik.is_open()){
        cout<<"Nie udalo sie otworzyc pliku...\n";
    }
    plik >> liczbaStudentow;
    wczytajStudentow(tab,liczbaStudentow);
    for(int i=0; i<2; i++){
        plik>>sredniki;
    }
    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss,tab[i].imie,';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].l_p=atoi(pomoc.c_str());
    }
    plik.close();
    return liczbaStudentow;
}

int podzial2czesci(student*& tab, int l_s, int granica){
    int i=0;
    int j=l_s-1;
    while(i < j){
        while (tab[i].l_p <= granica && i < j){
            i++;
        }
        while (tab[j].l_p > granica && i < j){
            j--;
        }
        if(i < j){
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if(tab[i].l_p <= granica){
        return i+1;
    }
    else{
        return i;
    }
}

void podzial3czesci(student*& tab, int l_s, int* tab2){
    int i=-1;
    int j=0;
    int k=l_s;
    while (j<k){
        if(tab[j].l_p%3==0){
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else{
            if(tab[j].l_p%3==2){
                k--;
                swap(tab[k], tab[j]);
            }
            else{
                j++;
            }
        }
    }
    tab2[0]=i;
    tab2[1]=k;
}

int main() {
    while(true) {
        student *tab;
        int wybor;
        int l_s = wczytywanieDanych(tab);
        cout << "Wybierz program :\n1 - Wczytywanie danych\n2 - podzial na 2 czesci\n3 - podzial na 3 czesci\n";
        cin>>wybor;
        if (wybor == 1) {
            wyswietlStudentow(tab, l_s);
        }
        else if (wybor == 2) {
            int gr = podzial2czesci(tab, l_s, 10);
            wyswietlStudentowP(tab, l_s, gr);
        }
        else if (wybor == 3) {
            int tab2[2];
            podzial3czesci(tab, l_s, tab2);
            wyswietlStudentowP2(tab, l_s, tab2[0], tab2[1]);
        }
        else {
            return 0;
        }
    }
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;
struct  student{
    string imie;
    string nazwisko;
    int l_p;
};

void przydzielPamiec1D(student *&tab, int n){
    tab = new student[n];
}

void usunTablice1D(student *&tab){
    delete []tab;
}

void wyswietl1D(int* tab, int n){
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void quickSort(int tab[],int l,int p, int tryb){
    int srodek =(int)(l+p)/2;
    int piwot = tab[srodek];
    tab[srodek]=tab[p];
    int granica = l;
    int i=l;
    while(i<p){
        bool t=tab[i]<piwot;
        if(tryb==1){
            t=tab[i]>piwot;
        }
        if(t){
            int temp = tab[granica];
            tab[granica] = tab[i];
            tab[i] = temp;
            granica++;
        }
        i++;
        }
    tab[p]=tab[granica];
    tab[granica]=piwot;
    if(l<granica-1){
        quickSort(tab,l,granica-1,tryb);
    }
    if(granica+1<p){
        quickSort(tab,granica+1,p,tryb);
    }
}

void sortowanieQuickSort(student* tab, int l, int p, int tryb){
    int srodek =(int)(l+p)/2;
    student piwot = tab[srodek];
    tab[srodek]=tab[p];
    int granica = l;
    int i=l;
    while(i<p){
        bool t=tab[i].l_p<piwot.l_p;
        if(tryb==1){
            t=tab[i].l_p>piwot.l_p;
        }
        if(t){
            student temp = tab[granica];
            tab[granica] = tab[i];
            tab[i] = temp;
            granica++;
        }
        i++;
    }
    tab[p]=tab[granica];
    tab[granica]=piwot;
    if(l<granica-1){
        sortowanieQuickSort(tab,l,granica-1,tryb);
    }
    if(granica+1<p){
        sortowanieQuickSort(tab,granica+1,p,tryb);
    }
}

void wczytajStudentow(student*&tab, int n){
    tab = new student[n];
}

void usunTabliceStudentow(student *&tab){
    delete []tab;
}

void wyswietlStudentow(student* tab, int n){
    for(int i=0;i<n;i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
}

int main() {
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    student* tab;
    sciezka="C:\\Users\\Mateusz\\Desktop\\jebacbarce\\studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;
    wczytajStudentow(tab,liczbaStudentow);
    for(int i=0;i<2;i++){
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
    sortowanieQuickSort(tab,0,liczbaStudentow-1,1);
    wyswietlStudentow(tab,liczbaStudentow);
    usunTabliceStudentow(tab);

    return 0;
}

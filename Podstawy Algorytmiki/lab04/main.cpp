#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void wczytajStudentow(student *&tab, int *liczba_studentow){
    string sciezka, linia;
    int liczbaStudentow;
    fstream plik;
    plik.open("C:\\Users\\Mateusz\\Desktop\\lab04\\studenci.csv");
    if(!plik.is_open()){
        cout<<"Nie mozna otworzyc pliku...";
    }
    char sredniki;
    plik >> liczbaStudentow;
    for(int i=0; i<2; i++){
        plik >> sredniki;
    }
    for(int i=0; i<liczbaStudentow; i++){
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        ss >> tab[i].punkty;
    }
    *liczba_studentow = liczbaStudentow;
    plik.close();
}

void wyswietlStudentow(student*tab, int n){
    for(int i=0; i<n; i++){
        cout<<"numer:"<<i+1<<"\nimie:"<<tab[i].imie<<endl;
        cout<<"nazwisko:"<<tab[i].nazwisko<<endl;
        cout<<"punkty:"<<tab[i].punkty<<endl;
        cout<<endl;
    }
}

void usunTabliceStudentow(student *&tab){
    delete [] tab;
}

void podzialNaDwieCzesci(student*tab, int n, int granica, int *koniec){
    int i=0, j=n-1;
    while(i < j){
        while(tab[i].punkty <= granica && i<j){
            i++;
        }
        while(tab[j].punkty>granica && i<j){
            j--;
        }
        if(i < j){
            swap(tab[i], tab[j]);
            i+=1;
            j-=1;
        }
    }
    if(tab[i].punkty <= granica){
        *koniec=i+1;
    }
    else{
        *koniec=i;
    }
}

void podzialNaDwieCzesci_wyswietl(student*tab, int n, int granica, int koniec){
    for(int i=0; i<n; i++){
        if(i==0){
            cout<<"Studenci ktorzy otrzymali <="<<granica<<" punktow:"<<endl;
            cout<<endl;
        }
        if(i < koniec){
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
            continue;
        }
        if(i==koniec){
            cout<<endl;
            cout<<"Studenci ktorzy otrzymali >"<<granica<<" punktow:"<<endl;
        }
        if(i >= koniec){
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
    }
}

void podzialNaTrzyCzesci(student *tab, int n, int *koniec1, int *koniec2){
    int i=-1, j=0, k=n;
    while(j < k){
        if(tab[j].punkty%3==0){
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else{
            if(tab[j].punkty%3==2){
                k--;
                swap(tab[k], tab[j]);
            }
            else{
                j++;
            }
        }
    }
    *koniec1=i;
    *koniec2=k;
}

void podzialNaTrzyCzesci_wyswietl(student *tab, int n, int kon1, int kon2){
    for(int i=0; i<n; i++){
        if(i <= kon1){
            if(i==0){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
        if(i>kon1 && i<kon2){
            if(i==kon1+1){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3 z reszta 1"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
        if(i>=kon2){
            if(i==kon2){
                cout<<"Studenci ktorzy maja liczbe punktow podzielna przez 3 z reszta 2"<<endl;
            }
            cout<<"Imie: "<<tab[i].imie<<endl;
            cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
            cout<<"Punkty: "<<tab[i].punkty<<endl;
        }
    }
}

int main() {
int wybor, granica, *koniec, *koniec1, *koniec2, kon, kon1, kon2, l_s=0, *wsk;
koniec1=&kon1;
koniec2=&kon2;
koniec=&kon;
wsk=&l_s;
cout<<"Wybierz program :\n1 - Wczytanie danych\n2 - Podzial zbioru na dwie czesci\n3 - Podzial zbioru na trzy czesci\n";
cin>>wybor;
    switch (wybor) {
        case 1: {
            cout << "Program wczytujacy dane...\n";
            student *tab2=new student[14];
            wczytajStudentow(tab2, wsk);
            wyswietlStudentow(tab2, l_s);
            break;
        }
        case 2: {
            cout << "Program do podzialu zbioru na dwie czesci...\n";
            student *tab2=new student[14];
            cout<<"Podaj granice :\n"; cin>>granica;
            podzialNaDwieCzesci(tab2, l_s, granica, koniec);
            podzialNaDwieCzesci_wyswietl(tab2, l_s, granica, kon);
            break;
        }
        case 3: {
            cout << "Program do podzialu zbioru na 3 czesci...\n";
            student *tab2=new student[14];
            podzialNaTrzyCzesci(tab2, l_s, koniec1, koniec2);
            podzialNaTrzyCzesci_wyswietl(tab2, l_s, kon1, kon2);
            break;
        }
        default: {
            cout << "Blad danych.\n";
        }
    }
            return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int liczba_punktow;
};

void wczytajStudentow(student *&tab, int n){
    tab = new student[n];
}

int wczytywanieDanych(student *&student){
    string sciezka, linia;
    int liczbaStudentow;
    ifstream plik;
    sciezka="C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab07\\studenci.csv";
    plik.open(sciezka);
    if(plik.is_open()){
        char sredniki;
        plik >> liczbaStudentow;
        wczytajStudentow(student, liczbaStudentow);
        for(int i=0; i<2; i++){
            plik >> sredniki;
        }
        for(int i=0; i<liczbaStudentow; i++){
            plik >> linia;
            stringstream ss(linia);
            getline(ss, student[i].imie, ';');
            getline(ss, student[i].nazwisko, ';');
            ss >> student[i].liczba_punktow;
        }
        plik.close();
    }
    else{
        cout<<"Nie mozna otworzyc pliku..."<<endl;
    }
    return liczbaStudentow;
}

void wyswietlStudentow(student *student, int n){
    for(int i=0; i<n; i++){
        cout<<student[i].imie<<" "<<student[i].nazwisko<<" "<<student[i].liczba_punktow<<endl;
    }
    cout<<endl;
}

void wyszukiwanieLiniowe(student *student, int n, int wartosc){
    int i=0, flaga=0;
    while(i < n){
        if(student[i].liczba_punktow == wartosc){
            flaga=1;
            cout<<student[i].imie<<" "<<student[i].nazwisko<<endl;
        }
        i++;
    }
    if(flaga == 0){
        cout<<"Zaden ze studentow nie posiada podanej liczby punktow..."<<endl;
    }
    cout<<endl;
}

void wyszukiwanieBisekcyjne(student *student, int n, int wartosc){
    int lewy=0;
    int prawy=n-1;
    string sciezka="C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab07\\wyniki.csv";
    ofstream zapis;
    zapis.open(sciezka);
    bool znaleziono = false;
    while(lewy <= prawy){
        int srodek=(int)(lewy+prawy)/2;
        if(student[srodek].liczba_punktow == wartosc){
            cout<<student[srodek].imie<<" "<<student[srodek].nazwisko<<" "<<student[srodek].liczba_punktow<<endl;
            zapis << student[srodek].imie << ";" << student[srodek].nazwisko << ";"<< student[srodek].liczba_punktow<<";"<<" "<<";";
            znaleziono = true;
            student[srodek].liczba_punktow=-1;
            continue;
        }
        else{
            if(wartosc < student[srodek].liczba_punktow){
                prawy=srodek;
            }
            else{
                lewy=srodek;
            }
        }
        if(prawy-lewy==1){
            break;
        }
    }
    if(!znaleziono){
        cout<<"Nie znaleziono zadnego studenta z iloscia punktow rowna : "<<wartosc<<endl;
    }
    zapis.close();
    cout<<endl;
}

int main() {
    while(true){
        student *tab;
        int wybor;
        int liczbaStudentow = wczytywanieDanych(tab);
        cout << "Wybierz program :\n1 - Wczytanie z pliku\n2 - Wyszukiwanie liniowe\n3 - Wyszukiwanie bisekcyjne\n";
        cin >> wybor;
        if(wybor == 1){
            wyswietlStudentow(tab, liczbaStudentow);
        }
        else if(wybor == 2){
            int wartosc;
            cout<<"Podaj liczbe punktow : "<<endl; cin>>wartosc;
            cout<<"Studenci ktorzy otrzymali "<<wartosc<<" punktow : "<<endl;
            wyszukiwanieLiniowe(tab, liczbaStudentow, wartosc);
        }
        else if(wybor == 3){
            int wartosc;
            cout<<"Podaj liczbe punktow : "<<endl; cin>>wartosc;
            wyszukiwanieBisekcyjne(tab, liczbaStudentow, wartosc);
        }
        else{
            cout<<"Podales zla wartosc..."<<endl;
            system("PAUSE");
            return 0;
        }
    }
}

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void wyszukiwanieLinniowe(student *student, int wartosc);
void wyszukiwanieBinarne(student *student, int wartosc);
void wczytywanieDanych(student *student);
void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb);

int main() {
    int wybor = -1, wartosc;
    student *tab = new student[20];
    while(wybor!=0){
        cout<<"Podaj z jakej funkcji chcesz skorzystac : "<<endl;
        cout<<"Wcisnij 1 jesli chcesz wczytac dane z pliku"<<endl;
        cout<<"Wcisnij 2 jesli chcesz wyszukac danych za pomoca algorytmu linniowego"<<endl;
        cout<<"Wcisnij 3 jesli chcesz wyszukac danych za pomoca algorytmu binarnego"<<endl;
        cout<<"Wcisnij 0 jesli chcesz wyjsc z aplikacji"<<endl;
        cout<<"Wybor :"<<endl; cin>>wybor;
        switch (wybor) {
            case 1: wczytywanieDanych(tab);
                quickSortDlaStruktur(tab,0,14,1);
                cout<<tab[0].imie;
                cout<<endl;
                break;
            case 2:
                cout<<"Podaj wartosc ktora szukasz :"<<endl; cin>>wartosc;
                wyszukiwanieLinniowe(tab,wartosc);
                cout<<endl;
                break;
            case 3:
                cout<<"Podaj wartosc ktora szukasz :"<<endl; cin>>wartosc;
                wyszukiwanieBinarne(tab,wartosc);
                cout<<endl;
                break;
            case 0: wybor=0;
                break;
            default:
                cout<<"Bledne dane!";
                break;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

void wyszukiwanieLinniowe(student *student, int wartosc){
    int i=0;
    bool znaleziono= false;
    while(i < 14){
        if(student[i].punkty == wartosc){
            cout<<student[i].imie<<" "<<student[i].nazwisko<<" "<<student[i].punkty<<endl;
            znaleziono= true;
        }
        i++;
    }
    if(!znaleziono){
        cout<<"Nie znaleziono zadnego studenta z iloscia punktow rowna: "<<wartosc<<endl;
    }
}

void wyszukiwanieBinarne(student *student, int wartosc){
    int lewy=0, prawy=14;
    ofstream zapis;
    string sciezkaDoZapisu="C:\\Users\\Mateusz\\Desktop\\lab07\\wyniki.csv";
    zapis.open(sciezkaDoZapisu);
    bool znaleziono=false;
    while(lewy <= prawy){
        int srodek=(int)(lewy+prawy)/2;
        if(student[srodek].punkty == wartosc){
            cout<<student[srodek].imie<<" "<<student[srodek].nazwisko<<" "<<student[srodek].punkty<<endl;
            zapis << student[srodek].imie << ";" << student[srodek].nazwisko << ";"<< student[srodek].punkty<<";"<<" "<<";";
            znaleziono= true;
            student[srodek].punkty=-1;
            continue;
        }
        else{
            if(wartosc < student[srodek].punkty){
                prawy=srodek;
            }
            else{
                lewy=srodek;
            }
        }
        if(prawy-lewy == 1){
            break;
        }
    }
    if(!znaleziono){
        cout<<"Nie znaleziono zadnego studenta z iloscia punktow rowna: "<<wartosc<<endl;
    }
    zapis.close();
}

void wczytywanieDanych(student *student){
    string sciezka,linia,pomoc;
    int liczbaStudentow;
    fstream plik;
    plik.open("C:\\Users\\Mateusz\\Desktop\\lab07\\studenci.csv");
    char sredniki;
    plik >> liczbaStudentow;
    for(int i=0; i<2; i++)
        plik >> sredniki;
    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, student[i].imie, ';');
        getline(ss, student[i].nazwisko, ';');
        ss >> student[i].punkty;
    }
    plik.close();
}

void quickSortDlaStruktur(student *tablica, int lewy,int prawy, int tryb){//quicksort dla struktur
    int srodek=(int)(lewy+prawy)/2;
    int piwot=tablica[srodek].punkty;
    student robocza1 = tablica[srodek];
    tablica[srodek]=tablica[prawy];
    tablica[prawy]=robocza1;
    int granica=lewy;
    int i=lewy;
    while(i < prawy){
        if(tryb) {
            if(tablica[i].punkty < piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        else{
            if(tablica[i].punkty > piwot){
                student robocza2=tablica[granica];
                tablica[granica]=tablica[i];
                tablica[i]=robocza2;
                granica+=1;
            }
        }
        i+=1;
    }
    student robocza3 = tablica[prawy];
    tablica[prawy]=tablica[granica];
    tablica[granica]=robocza3;
    if(lewy < granica-1){
        quickSortDlaStruktur(tablica,lewy,granica-1,tryb);
    }
    if(granica+1 < prawy){
        quickSortDlaStruktur(tablica,granica+1,prawy,tryb);
    }
}

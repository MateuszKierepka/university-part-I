#include <iostream>
#include <string>

namespace kolega1{char imie[] = "Mateusz"; int wiek = 20; }
namespace kolega2{char imie[] = "Mikolaj"; int wiek = 21; }

using namespace std;
using namespace kolega1;

struct pracownik{
    char imie[20];
    char nazwisko[20];
    int stawka_za_godzine;
    int liczba_godzin;
    char data_zatrudnienia[30];
};

struct student{
    char imie[20];
    char nazwisko[20];
};



int main() {

    cout<<"Dane: "<<imie<<" , "<<wiek<<endl;
    cout<<"Dane: "<<kolega2::imie<<" , "<<kolega2::wiek<<endl;

    int x;
    cout<<"Podaj liczbe w systemie dziesiatkowym : "<<endl;
    cin>>x;
    cout<<"Liczba w systemie osemkowym : "<<oct<<x<<endl;
    cout<<"Liczba w systemie szesnastkowym : "<<hex<<x<<endl;

    int n;
    cout<<"podaj liczbe pracownikow : "<<endl;
    cin>>n;
    struct pracownik dane[n];
    for(int i=0; i<n; i++) {
        fflush(stdin);
        cout << "Podaj imie i nazwisko : " << endl;
        cin >> dane[i].imie >> dane[i].nazwisko;
        cout << "Podaj stawke i liczbe przepracowanych godzin : " << endl;
        cin >> dane[i].stawka_za_godzine >> dane[i].liczba_godzin;
        cout << "Data zatrudnienia?" << endl;
        cin >> dane[i].data_zatrudnienia;
    }
    for(int i=0; i<n; i++){
        cout<<"Wyplata dla "<<dane[i].imie<<" "<<dane[i].nazwisko<<" wynosi : "<<dane[i].liczba_godzin*dane[i].stawka_za_godzine<<endl;
    }

    int a;
    float srednia, e1, e2, e3;
    cout<<"Podaj liczbe studentow : "<<endl;
    cin>>a;
    struct student informacje[a];
    for(int i=0; i<a; i++){
        fflush(stdin);
        cout<<"student "<<i+1<<" : Podaj imie i nazwisko : "<<endl;
        cin>>informacje[i].imie>>informacje[i].nazwisko;
    }
    for(int i=0; i<a; i++){
        cout<<"student "<<i+1<<" : Podaj wyniki 3 egzaminow : "<<endl;
        cin>>e1>>e2>>e3;
        srednia = (e1 + e2 + e3) / 3;
        cout<<"Srednia ocen z egzamin "<<informacje[i].imie<<" "<<informacje[i].nazwisko<<" wynosi "<<srednia<<endl;
    }
    return 0;
}

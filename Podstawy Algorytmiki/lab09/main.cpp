#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//9.1
struct element{
    int number;
    element * next;
};

void push(element *&Stack, int value);
void pop(element *&Stack);
bool isEmpty(element *Stack);
int top(element *Stack);

//9.2
struct elementT{
    char litera;
    elementT * next;
};

void pushT(elementT *&Stack, string litera);
void popT (elementT *&Stack);
bool isEmptyT(elementT *Stack);
char topT(elementT *Stack);

void lab_9_1();
void lab_9_2();


int main(){
    int n, wybor=-1;
    while(wybor != 0){
        cout<<"Wybierz funkcje :\n1 - 9.1\n2 - 9.2\n0 - wyjscie"<<endl; cin>>wybor;
        switch (wybor) {
            case 1:{
                lab_9_1();
                cout<<endl;
                break;
            }
            case 2:{
                lab_9_2();
                cout<<endl;
                break;
            }
            case 0:
                wybor=0;
                break;
            default:
                cout<<"Bledne dane!"<<endl;
                cout<<endl;
                break;
        }
    }
    return 0;
}

//9.1
void push(element *&Stack, int value){
    element *el = new element;
    el->number = value;
    el->next = Stack;
    Stack = el;
}

void pop(element *&Stack){
    if (!isEmpty(Stack)){
        element *temp = Stack;
        Stack = Stack->next;
        delete temp;
    }
}

bool isEmpty(element *Stack){
    return (Stack==nullptr);
}

int top(element *Stack){
    if(!isEmpty(Stack))
        return Stack->number;
    return -1;
}

//9.2
void push(elementT *&Stack, char litera){
    elementT *el = new elementT;
    el->litera = litera;
    el->next = Stack;
    Stack = el;
}

void popT(elementT *& Stack){
    if (!isEmptyT(Stack)){
        elementT *temp = Stack;
        Stack = Stack->next;
        delete temp;
    }
}
bool isEmptyT(elementT *Stack){
    return (Stack==nullptr);
}
char topT(elementT *Stack){
    if(!isEmptyT(Stack))
        return Stack->litera;
    return '1';
}

//9.1
void wyswitlStack(element Stack){
    bool stop = false;
    element *TEMP = &Stack;
    while(!stop){
        if (!isEmpty(TEMP)){
            element *temp = TEMP;
            cout << TEMP->number << " ";
            TEMP = TEMP->next;
            delete temp;
        }
        else
            stop = true;
    }
    cout << endl;
}

void lab_9_1(){
    element* Stack=nullptr;
    element* Temp =nullptr;
    int n=-1, delEl, temp, ost;
    bool stop;
    while(n != 6) {
        cout << "Podaj nr zadanka:" << endl
             << "1 - 1) sprawdzenie czy stos jest pusty, powinien zostac wyswietlony odpowiedni komunikat\n"
             << "2 - 2) dodanie elementu na stos, liczbe, ktora powinna byc dodana do stosu, nalezy wylosowac z zakresu 1 - 10.\n"
             << "3 - 3) usuniecie elementu ze stosu, jesli na stosie nie ma zadnego elementu nalezy wyswietlic stosowny komunikat, na przyklad: Stos jest pusty.\n"
             << "4 - 4) pobranie elementu ze stosu, nalezy wyswietlic ostatni element, ktory znajduje sie nastosi\n"
             << "5 - 5) usuniecie wszystkich elementow ze stosu, nalezy usunac wszystkie elementy na stosie poprzez zdejmowanie kolejnych elementow ze stosu.\n"
             << "6 - 6) wyjscie z programu\n";
        cin >> n;
        switch (n) {
            case 1:
                if (isEmpty(Stack))
                    cout << "Stos jest pusty!" << endl;
                else {
                    cout << "Stos jest czyms pelny!" << endl;
                    wyswitlStack(*Stack);
                }
                system("pause");
                break;
            case 2:
                cout << "Podaj liczbe elementow stosa: ";
                cin >> n;
                cout << "Podaj liczbe od 1 do 10" << endl;
                for (int i = 0; i < n;) {
                    cin >> temp;
                    if (temp >= 1 && temp <= 10) {
                        i++;
                        push(Stack, temp);
                    } else
                        cout << "To nie byla liczba z zakresu 1-10!" << endl;
                }
                break;
            case 3:
                cout << "Ile elementow chcesz usanac: ";
                cin >> delEl;
                for (int i = 0; i < delEl; i++) {
                    pop(Stack);
                }
                if (isEmpty(Stack))
                    cout << "Stos jest pusty!" << endl;
                else {
                    cout << "Stos jest czyms pelny!" << endl;
                    //wyswitlStack(Stack);
                }
                system("pause");
                break;
            case 4:
                ost = top(Stack);
                if (ost != -1)
                    cout << "Ostatni stos - " << ost << endl;
                else
                    cout << "Stos juz jest pusty!" << endl;
                system("pause");
                break;
            case 5:
                stop = false;
                while (!stop) {
                    if (!isEmpty(Stack)) {
                        pop(Stack);
                    } else
                        stop = true;
                }
                cout << "Wszytkie elementy zostaly usuniete!" << endl;
                system("pause");
                break;
            case 6:
                delete Stack;
                n = 6;
                break;
            default:
                break;
        }
    }
}

//9.2

void zapisWynika(elementT *tekst){
    ofstream zapis;
    zapis.open("C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab09\\wyniki.txt");
    bool stop = false;
    while(!stop){
        if (!isEmptyT(tekst)){
            zapis << topT(tekst);
            popT(tekst);
        }
        else
            stop = true;
    }
    zapis.close();
}

void wczytajPlik(elementT *&litery){
    ifstream plik, plikTemp;

    char sim;

    plikTemp.open("C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab09\\znaki1.txt");
    plik.open("C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab09\\znaki1.txt");
    int dl = 0;
    while (plikTemp.get(sim))
        dl ++;
    plikTemp.close();
    int i = 0;
    while (plik.get(sim) && i<dl){
        push(litery,sim);
        i++;
    }
    plik.close();
}

void lab_9_2(){
    elementT* tekst=nullptr;
    cout << "Wczytanie pliku!" << endl;
    wczytajPlik(tekst);
    cout << "Odwrocenie kolejnosci" << endl;
    zapisWynika(tekst);
}
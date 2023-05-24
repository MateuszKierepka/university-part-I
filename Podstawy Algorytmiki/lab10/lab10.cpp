#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element {
    char character;
    element* next;
};

struct queue {
    element* head;
    element* tail;
};

bool isEmpty(queue q) {
    if (q.head == nullptr) {
        return true;
    }
    else{
        return false;
    }
}

void push(queue& q, char value) {
    element* el = new element;
    el->character = value;
    el->next = nullptr;
    if (q.tail != nullptr) {
        q.tail->next = el;
    }
    else {
        q.head = el;
    }
    q.tail = el;
}   

void pop(queue& q) {
    element* temp = q.head;
    q.head = q.head->next;
    delete temp;
    if (q.head == nullptr) {
        q.tail == nullptr;
    }
}

char first(queue q) {
    return q.head->character;
}

void wyswietl(queue& q) {
    queue q1;
    q1.head = nullptr;
    q1.tail = nullptr;
    char character;
    cout << "Kolejka : ";
    while (!isEmpty(q)) {
        character = first(q);
        cout << character << ", ";
        push(q1, character);
        pop(q);
    }
    cout << endl;
}

void wczytaj(queue& q) {
    ifstream plik;
    char znak;
    plik.open("znaki2.txt");
    while (plik.get(znak)) {
        if (65 <= znak && 90 >= znak) {
            push(q, znak);
        }
    }
    plik.close();
}

void losowanie(queue* queue){
    char random = 'A' + rand() % 26;
    element* el = new element;
    el->character=random;
    cout<<"Losowanie elementu... "<<el->character<<"!!"<<endl;
    el->next= nullptr;
    if(isEmpty(*queue)){
        queue->head = el;
        queue->tail = el;
    }
    else{
        queue->tail->next = el;
        queue->tail = el;
    }
}

int main(){
    queue q;
    q.head = nullptr;
    q.tail = nullptr;

    int wybor = 0, n;
    char temp;
    while (wybor != 8) {
        cout << endl;
        cout << "Wybierz program : " << endl;
        cout << "1 - Sprawdzenie czy kolejka jest pusta" << endl;
        cout << "2 - Wyswietlenie kolejki" << endl;
        cout << "3 - Dodanie losowego elementu do kolejki" << endl;
        cout << "4 - Usuniecie elementu z kolejki" << endl;
        cout << "5 - Wyswietl pierwszy znak z kolejki" << endl;
        cout << "6 - Usuniecie wszystkich elementow z kolejki" << endl;
        cout << "7 - Dodanie duzych liter do kolejki z pliku znaki2.txt" << endl;
        cout << "8 - Wyjscie z programu" << endl;
        cin >> wybor;

        switch (wybor) {
        case 1: {
            if (isEmpty(q)) {
                cout << "Kolejka jest pusta!" << endl;
            }
            else {
                cout << "Kolejka nie jest pusta!" << endl;
            }
            break;
        }
        case 2: {
            wyswietl(q);
            break;
        }
        case 3: {
            srand(time(NULL));
            losowanie(&q);
            break;
        }
        case 4: {
            if (!isEmpty(q)) {
                    pop(q);
            }
            break;
        }
        case 5: {
            if (isEmpty(q)) {
                cout << "Kolejka jest pusta!" << endl;
            }
            else {
                first(q);
            }
            break;
        }
        case 6: {
            while (!isEmpty(q)) {
                pop(q);
            }
            cout << "Elementy zostaly usuniete" << endl;
            break;
        }
        case 7: {
            wczytaj(q);
            break;
        }
        case 8: {
            return 0;
        }
        default:
            cout << "Blad danych!";
            wybor = 8;
            break;
        }
    }
    return 0;
}

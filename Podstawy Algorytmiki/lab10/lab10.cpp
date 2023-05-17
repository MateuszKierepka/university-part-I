#include <iostream>
#include <fstream>


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
        cout << "3 - Dodanie elementu do kolejki" << endl;
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
            cout << "Ile elementow chcesz dodac?" << endl; cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Podaj znak : " << endl; cin >> temp;
                push(q, temp);
            }
            break;
        }
        case 4: {
            if (!isEmpty(q)) {
                cout << "Ile elementow chcesz usunac?" << endl; cin >> n;
                for (int i = 0; i < n; i++) {
                    pop(q);
                }
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
}

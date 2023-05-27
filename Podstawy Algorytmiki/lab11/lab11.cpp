#include <iostream>
#include <cstdlib>

using namespace std;

struct element {
    int number;
    element* next;
};

struct single_list {
    element* head;
    element* tail;
    int counter;
};


bool isEmpty(single_list list) {
    return (list.tail == nullptr && list.head == nullptr);
}

void add_tail(single_list& list, int value) {
    element* el = new element;
    el->number = value;
    el->next = list.head;
    if (list.tail != nullptr) {
        list.tail->next = el;
    }
    else {
        list.head = el;
    }
    list.tail = el;
    list.counter++;
}

void add_head(single_list& list, int value) {
    element* el = new element;
    el->number = value;
    el->next = list.head;
    list.head = el;
    if (list.tail == nullptr) {
        list.tail = el;
    }
    list.counter++;
}

void add_position(single_list& list, int value, int position) {
    element* el = new element;
    el->number = value;
    element* temp = list.head;
    if (position <= 1) {
        add_head(list, value);
        return;
    }
    if (position > list.counter) {
        add_tail(list, value);
        return;
    }
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    el->next = temp->next;
    temp->next = el;
    list.counter++;
}

void delete_tail(single_list& list) {
    element* temp = list.tail;
    if (list.counter == 1) {
        list.tail = nullptr;
        list.head = nullptr;
    }
    else {
        element* bef_temp = list.head;
        for (int i = 1; i < list.counter - 1; i++) {
            bef_temp = bef_temp->next;
        }
        list.tail = bef_temp;
        list.tail->next = nullptr;
    }
    delete temp;
    list.counter--;
}

void delete_head(single_list& list) {
    element* temp = list.head;
    list.head = list.head->next;
    if (list.counter == 1) {
        list.tail = nullptr;
    }
    delete temp;
    list.counter--;
}

void delete_position(single_list& list, int position) {
    if (position < 1 || position > list.counter) {
        cout << "Nieprawidlowa pozycja!" << endl;
        return;
    }
    if (position == 1) {
        delete_head(list);
        return;
    }
    if (position == list.counter) {
        delete_tail(list);
        return;
    }
    element* prev = list.head;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
    }
    element* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    list.counter--;
}

void show(single_list list) {
    element* temp = list.head;
    for (int i = 0; i < list.counter; i++) {
        cout <<"Element "<< i+1 <<" : " << temp->number << endl;
        temp = temp->next;
    }
}

float srednia_arytmetyczna(single_list list) {
    float srednia = 0;
    element* temp = list.head;
    for (int i = 0; i < list.counter; i++) {
        srednia += temp->number;
        temp = temp->next;
    }
    return srednia / list.counter;
}

void max(single_list list) {
    int max = 0;
    int position;
    element* temp = list.head;
    for (int i = 0; i < list.counter; i++) {
        if (max < temp->number) {
            max = temp->number;
            position = i+1;
        }
        else {
            temp = temp->next;
        }
    }

    cout << "Najwieksza liczba to " << max << " ktora jest " << position << " elementem!" << endl;
}

int gen_liczb() {
    int a = 1;
    int b = 50;
    return rand() % (b - a + 1) + a;
}

int main() {
    single_list list;
    list.head = nullptr;
    list.tail = nullptr;
    list.counter = 0;
    int choice = 0, value, position;

    while (choice != 14) {
        cout << "Wybierz funkcje :" << endl;
        cout << "1 - Sprawdzenie czy lista jest pusta" << endl;
        cout << "2 - Dodanie elementu na koniec listy" << endl;
        cout << "3 - Dodanie elementu na poczatek listy" << endl;
        cout << "4 - Dodanie elementu na okreslona pozycje" << endl;
        cout << "5 - Usuniecie elementu z konca listy" << endl;
        cout << "6 - Usuniecie elementu z poczatku listy" << endl;
        cout << "7 - Usuniecie elementu znajdujacego sie na okreslonej pozycji" << endl;
        cout << "8 - Pobranie pierwszego elementu z listy" << endl;
        cout << "9 - Pobranie ostatniego elementu z listy" << endl;
        cout << "10 - Policzenie sredniej arytmetycznej elementow w liscie" << endl;
        cout << "11 - Znalezienie elementu maksymalnego w liscie" << endl;
        cout << "12 - Wyswietlenie calej listy" << endl;
        cout << "13 - Usuniecie calej listy wraz ze zwolnieniem pamieci" << endl;
        cout << "14 - Wyjscie z programu" << endl;
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                cout << "Lista ma " << list.counter << " elementow!" << endl;
            }
            cout << endl;
            break;

        case 2:
            value = gen_liczb();
            add_tail(list, value);
            cout << "Liczba " << value << " zostala dodana na koniec listy!" << endl;
            show(list);
            cout << endl;
            break;

        case 3:
            value = gen_liczb();
            add_head(list, value);
            cout << "Liczba " << value << " zostala dodana na poczatek listy!" << endl;
            show(list);
            cout << endl;
            break;

        case 4:
            value = gen_liczb();
            cout << "Podaj pozycje : " << endl; 
            cin >> position;
            add_position(list, value, position);
            cout << "Liczba " << value << " zostala dodana na pozycje " << position << "!" << endl;
            show(list);
            cout << endl;
            break;

        case 5:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                delete_tail(list);
                cout << "Usunieto koncowy element z listy!" << endl;
            }
            show(list);
            cout << endl;
            break;

        case 6:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                delete_head(list);
                cout << "Usunieto poczatkowy element z listy!" << endl;
            }
            show(list);
            cout << endl;
            break;

        case 7:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                cout << "Podaj pozycje od 1 do " << list.counter << ": " << endl;
                cin >> position;
                delete_position(list, position);
                cout << "Usunieto element z " << position << " pozycji!" << endl;
                show(list);
            }
            cout << endl;
            break;

        case 8:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                cout << "Pierwszy element listy wynosi : " << list.head->number << endl;
            }
            cout << endl;
            break;

        case 9:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                cout << "Ostatni element listy wynosi : " << list.tail->number << endl;
            }
            cout << endl;
            break;

        case 10:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                cout << "Srednia arytmetyczna elementow wynosi : " << srednia_arytmetyczna(list);
            }
            cout << endl;
            break;

        case 11:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                max(list);
            }
            cout << endl;
            break;

        case 12:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                show(list);
            }
            cout << endl;
            break;

        case 13:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
           }
            else {
                while (!isEmpty(list)) {
                    delete_tail(list);
                }
                cout << "Usunieto wszystkie elementy!" << endl;
            }
            cout << endl;
            break;

        case 14:
            system("pause");
            return EXIT_SUCCESS;

        default:
            cout << "Blad danych!" << endl;
            break;
        }
    }
    system("pause");
    return EXIT_SUCCESS;
}
#include <iostream>
#include <cstdlib>

using namespace std;

int gen_liczb(int a, int b) {
    return rand() % (b - a + 1) + a;
}

struct element {
    int number;
    element* prev;
    element* next;
};

struct double_list_cykliczna {
    element* biezacy;
};

bool isEmpty(double_list_cykliczna list) {
    return (list.biezacy == nullptr);
}

void add_tail(double_list_cykliczna& list, int value) {
    element* el = new element;
    if (list.biezacy == nullptr) {
        el->number = value;
        el->next = el;
        el->prev = el->next;
        list.biezacy = el;
        return;
    }
    element* end = list.biezacy;
    el->next = end->next;
    el->number = value;
    el->prev = end;
    end->next = el;
    end = el;
    end->next->prev = end;
}

void add_head(double_list_cykliczna& list, int value) {
    element* el = new element;
    if (list.biezacy == nullptr) {
        el->number = value;
        el->next = el;
        el->prev = el->next;
        list.biezacy = el;
        return;
    }
    element* prev = list.biezacy;
    el->number = value;
    el->prev = prev;
    el->next = list.biezacy;
    prev->next = el;
    list.biezacy->prev = el;
}

void delete_tail(double_list_cykliczna& list) {
    element* el = list.biezacy->next;
    list.biezacy->next = el->next;
    list.biezacy->next->prev = el->prev;
    if (el->next == el) {
        list.biezacy = nullptr;
    }
    delete el;
}

void delete_head(double_list_cykliczna& list) {
    element* end = list.biezacy->prev->prev;
    element* el = end->next;
    element* pom = el;
    if (el->next == el) {
        pom = list.biezacy->next;
        list.biezacy = nullptr;
    }
    else {
    end->next = list.biezacy;
    list.biezacy->prev = el->prev;
    }
    delete pom;
}

int ileElementow(double_list_cykliczna& list) {
    int elementy = 0;
    if (isEmpty(list)) {
        return elementy;
    }
    element* temp = list.biezacy;
    while (temp != list.biezacy) {
        elementy++;
        temp = temp->next;
    }
    return elementy;
}

void show(double_list_cykliczna list, int tryb) {
    element* temp = list.biezacy;
    int i = 1;
    do {
        if (i == 1) {
            cout << i << "B - " << temp->number << endl;
        }
        else {
            cout << i << " - " << temp->number << endl;
        }
        if (tryb == 0) {
            temp = temp->next;
        }
        else {
            temp = temp->prev;
        }
        i++;
    } while (temp != list.biezacy);
}

int main() {
    double_list_cykliczna list;
    list.biezacy = nullptr;
    int wybor = 0, value;

    while (wybor != 7) {
        cout << "Wybierz program : " << endl;
        cout << "1 - Dodaj element po biezacym" << endl;
        cout << "2 - Dodaj element przed biezacym" << endl;
        cout << "3 - Usun element stojacy po biezacym" << endl;
        cout << "4 - Usun element stojacy przed biezacym" << endl;
        cout << "5 - Ile elementow ma lista" << endl;
        cout << "6 - Wydruk listy" << endl;
        cout << "7 - WYjscie z programu" << endl;
        cin >> wybor;
        system("cls");

        switch (wybor) {
        case 1:
            value = gen_liczb(1, 50);
            add_tail(list, value);
            cout << "Dodano " << value << " po biezacym elemencie!" << endl;
            show(list, 0);
            cout << endl;
            break;

        case 2:
            value = gen_liczb(1, 50);
            add_head(list, value);
            cout << "Dodano " << value << " przed biezacym elementem!" << endl;
            show(list, 0);
            cout << endl;
            break;

        case 3:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                delete_tail(list);
                cout << "Usunieto element stojacy po biezacym!" << endl;
            }
            cout << endl;
            break;

        case 4:
            if (isEmpty(list)) {
                cout<<"Lista jest pusta!"<<endl;
            }
            else {
                delete_head(list);
                cout << "Usunieto element stojacy przed biezacym!" << endl;
            }
            cout << endl;
            break;

        case 5:
            cout << "Lista ma " << ileElementow(list) << " elementow!" << endl;
            cout << endl;
            break;

        case 6:
            if (isEmpty(list)) {
                cout << "Lista jest pusta!" << endl;
            }
            else {
                show(list, 0);
            }
            cout << endl;
            break;

        case 7:
            system("pause");
            return EXIT_SUCCESS;

        default:
            cout << "Blad danych!" << endl;
            wybor = 7;
            break;
        }

    }
    system("pause");
    return EXIT_SUCCESS;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

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

bool isEmpty(single_list lista) {
	if (lista.tail == nullptr && lista.head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void add_tail(single_list& lista, int value) {
	element* el = new element;
	el->number = value;
	el->next = nullptr;
	if (lista.tail != nullptr) {
		lista.tail->next = el;
	}
	else {
		lista.head = lista.tail;
	}
	lista.tail = el;
}

void add_head(single_list& lista, int value) {
	element* el = new element;
	el->number = value;
	el->next = lista.head;
	lista.head = el;
	if (lista.tail == nullptr) {
		lista.tail = el;
	}
}

void add_position(single_list& lista, int value, int position) {
	element* el = new element;
	el->number = value;
	element* temp = lista.head;
	int i = 1;
	while (i < position - 1) {
		temp = temp->next;
		i++;
	}
	el->next = temp->next;
	temp->next = el;
}

void delete_tail(single_list& lista) {
	lista.counter--;
	element* temp = lista.tail;
	if (lista.counter == 1) {
		lista.tail = nullptr;
		lista.head = nullptr;
	}
	else {
		element* bef_temp = lista.head;
		for (int i = 1; i < lista.counter - 1; i++) {
			lista.tail = bef_temp;
			lista.tail->next = nullptr;
		}
	}
	delete temp;
}

void delete_head(single_list& lista) {
	lista.counter--;
	element* temp = lista.head;
	lista.head = lista.head->next;
	if (lista.counter == 1) {
		lista.tail = nullptr;
	}
	delete temp;
}

void delete_position(single_list& lista, int position) {
	lista.counter--;
	element* prev = lista.head;
	for (int i = 1; i < position - 1; i++) {
		prev = prev->next;
	}
	
}

bool isEmpty_Element(element el) {
	if (el.next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

float sredniaArytmetyczna(single_list& lista) {
	float srednia = 0;
	element* temp = lista.head;
	for (int i = 0; i < lista.counter - 1; i++) {
		srednia += temp->number;
		if (!isEmpty_Element(*temp)) {
			temp = temp->next;
		}
	}
	return srednia / (lista.counter - 1);
}

int maksymalny(single_list& lista) {
	int max = 0;
	element* temp = lista.head;
	for (int i = 1; i < lista.counter - 1; i++) {
		if (max < temp->number) {
			max = temp->number;
		}
		if (!isEmpty_Element(*temp)) {
			temp = temp->next;
		}
	}
	return max;
}

void show(single_list lista) {
	element* temp = lista.head;
	cout << "Lista jednokierunkowa : " << endl;
	for (int i = 1; i < lista.counter - 1; i++) {
		cout << i << " - " << temp->number << endl;
		if (!isEmpty_Element(*temp)) {
			temp = temp->next;
		}
	}
}

int main(){
	setlocale(LC_ALL, "");
	single_list lista;
	lista.head = nullptr;
	lista.tail = nullptr;
	lista.counter = 1;

	int wybor = 0, value, position=0;

	while (wybor != 14) {
		cout << "Wybierz funkcję :" << endl;
		cout << "1 - Sprawdzenie czy lista jest pusta" << endl;
		cout << "2 - Dodanie elementu na koniec listy" << endl;
		cout << "3 - Dodanie elementu na początek listy" << endl;
		cout << "4 - Dodanie elementu na określoną pozycję" << endl;
		cout << "5 - Usunięcie elementu z końca listy" << endl;
		cout << "6 - Usunięcie elementu z początku listy" << endl;
		cout << "7 - Usunięcie elementu znajdującego się na określonej pozycji" << endl;
		cout << "8 - Pobranie pierwszego elementu z listy" << endl;
		cout << "9 - Pobranie ostatniego elementu z listy" << endl;
		cout << "10 - Policzenie średniej arytmetycznej elementów w liście" << endl;
		cout << "11 - Znalezienie elementu maksymalnego w liście" << endl;
		cout << "12 - Wyświetlenie całej listy" << endl;
		cout << "13 - Usunięcie całej listy wraz ze zwolnieniem pamięci" << endl;
		cout << "14 - Wyjście z programu" << endl;
		cin >> wybor;

		switch (wybor) {
		case 1:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Lista ma " << lista.counter - 1 << " elementów" << endl;
			}
			cout << endl;
			break;
		case 2:
			srand(time(NULL));
			value = rand() % 49 + 1;
			cout << "Wylosowana liczba : " << value << endl;
			add_tail(lista, value);
			cout << endl;
			break;
		case 3:
			srand(time(NULL));
			value = rand() % 49 + 1;
			cout << "Wylosowana liczba : " << value << endl;
			add_head(lista, value);
			cout << endl;
			break;
		case 4:
			srand(time(NULL));
			value = rand() % 49 + 1;
			cout << "Wylosowana liczba : " << value << endl;
			while (position <= 0) {
				cout << "Na którą pozycję chcesz dodać element?" << endl;
				cin >> position;
			}
			add_position(lista, value, position);
			cout << endl;
			break;
		case 5:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				delete_tail(lista);
				cout << "Usunięto końcowy element z listy" << endl;
			}
			cout << endl;
			break;
		case 6:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				delete_head(lista);
				cout << "Usunięto początkowy element z listy" << endl;
			}
			cout << endl;
			break;
		case 7:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				while (position <= 0) {
					cout << "Z której pozycji chcesz usunąć element?" << endl;
					cin >> position;
				}
				delete_position(lista, position);
				cout << "Usunięto element z listy o indeksie " << position << endl;
			}
			cout << endl;
			break;
		case 8:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Pierwszy element listy : " << lista.head->number << endl;
			}
			cout << endl;
			break;
		case 9:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Ostatni element listy : " << lista.tail->number << endl;
			}
			cout << endl;
			break;
		case 10:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Średnia arytmetyczna elementów listy wynosi : " << sredniaArytmetyczna(lista) << endl;
			}
			cout << endl;
			break;
		case 11:
			if (isEmpty(lista)){
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Element maksymalny w liście wynosi : " << maksymalny(lista) << endl;
			}
			cout << endl;
			break;
		case 12:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				show(lista);
			}
			cout << endl;
			break;
		case 13:
			if (isEmpty(lista)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				while (!isEmpty(lista)) {
					delete_tail(lista);
				}
				cout << "Wszystkie elementy zostały usunięte!" << endl;
			}
			cout << endl;
			break;
		case 14:
			system("PAUSE");
			return EXIT_SUCCESS;
		default:
			cout << "Błąd danych!" << endl;
			wybor = 14;
			break;
		}
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element {
	int number;
	element* next;
	element* prev;
};

struct double_list {
	element* head;
	element* tail;
	int counter;
};

bool isEmpty(double_list list) {
	return (list.tail == nullptr && list.head == nullptr);
}

void add_tail(double_list& list, int value) {
	element* el = new element;
	el->number = value;
	el->next = nullptr;
	el->prev = nullptr;
	if (list.tail != nullptr) {
		list.tail->next = el;
		el->prev = list.tail;
	}
	else {
		list.head = el;
	}
	list.tail = el;
	list.counter++;
}

void add_head(double_list& list, int value) {
	element* el = new element;
	el->number = value;
	el->next = nullptr;
	el->prev = nullptr;
	if (list.head != nullptr) {
		list.head->prev = el;
		el->next = list.head;
	}
	else {
		list.tail = el;
	}
	list.head = el;
	list.counter++;
}

void add_position(double_list& list, int value, int position) {
	if (position == 1) {
		add_head(list, value);
		return;
	}
	if (position == list.counter + 1) {
		add_tail(list, value);
		return;
	}
	else {
		element* temp = list.head;
		for (int i = 1; i < position - 1; i++) {
			temp = temp->next;
		}
		element* el = new element;
		el->number = value;
		el->prev = temp;
		el->next = temp->next;
		temp->next->prev = el;
		temp->next = el;
	}
	list.counter++;
}

void delete_tail(double_list& list) {
	element* temp = list.tail;
	if (list.counter == 1) {
		list.tail = nullptr;
		list.head = nullptr;
	}
	else {
		list.tail = list.tail->prev;
		list.tail->next = nullptr;
	}
	delete temp;
	list.counter--;
}

void delete_head(double_list& list) {
	element* temp = list.head;
	if (list.counter == 1) {
		list.tail = nullptr;
		list.head = nullptr;
	}
	else {
		list.head = list.head->next;
		list.head->prev = nullptr;
	}
	delete temp;
	list.counter--;
}

void delete_position(double_list& list, int position) {
	element* temp = list.head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
	}
	element* temp_us = temp->next;
	temp->next = temp_us->next;
	temp->next->prev = temp;
	delete temp_us;
	list.counter--;
}

void show(double_list list, int tryb) {
	if (tryb == 0) {
		element* temp = list.head;
		for (int i = 0; i < list.counter; i++) {
			cout << "Element " << i + 1 << " : " << temp->number << endl;
			temp = temp->next;
		}
	}
	else if (tryb == 1) {
		element* temp = list.tail;
		for (int i = 0; i < list.counter; i++) {
			cout << "Element " << list.counter - i << " : " << temp->number << endl;
			temp = temp->prev;
		}
	}
}

void min(double_list list) {
	int min = 50;
	int position = 0;
	element* temp = list.head;
	for (int i = 0; i < list.counter; i++) {
		if (min > temp->number) {
			min = temp->number;
			position = i + 1;
			temp = temp->next;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "Najmniejsza liczba to " << min << " ktora jest " << position << " elementem!" << endl;
}

int gen_liczb() {
	int a = 1;
	int b = 50;
	return rand() % (b - a + 1) + a;
}

int main(){
	double_list list;
	list.head = nullptr;
	list.tail = nullptr;
	list.counter = 0;
	int choice = 0, value, position;

	while (choice != 12) {
		cout << "Wybierz funkcje :" << endl;
		cout << "1 - Sprawdzenie czy lista jest pusta" << endl;
		cout << "2 - Dodanie elementu na koniec listy" << endl;
		cout << "3 - Dodanie elementu na poczatek listy" << endl;
		cout << "4 - Dodanie elementu na okreslona pozycje" << endl;
		cout << "5 - Usuniecie elementu z konca listy" << endl;
		cout << "6 - Usuniecie elementu z poczatku listy" << endl;
		cout << "7 - Usuniecie elementu znajdujacego sie na okreslonej pozycji" << endl;
		cout << "8 - Wyswietlenie elementow od poczatku do konca" << endl;
		cout << "9 - Wyswietlenie elementow od konca do poczatku" << endl;
		cout << "10 - Znalezienie elementu minimalnego w liscie" << endl;
		cout << "11 - Usuniecie calej listy wraz ze zwolnieniem pamieci" << endl;
		cout << "12 - Wyjscie z programu" << endl;
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
			show(list, 0);
			cout << endl;
			break;

		case 3:
			value = gen_liczb();
			add_head(list, value);
			cout << "Liczba " << value << " zostala dodana na poczatek listy!" << endl;
			show(list, 0);
			cout << endl;
			break;

		case 4:
			value = gen_liczb();
			cout << "Podaj pozycje : " << endl;
			cin >> position;
			while (position < 0 || position > list.counter + 1) {
				cout << "Podaj pozycje jeszcze raz : " << endl;
				cin >> position;
			}
			add_position(list, value, position);
			cout << "Liczba " << value << " zostala dodana na pozycje " << position << "!" << endl;
			show(list, 0);
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
			show(list, 0);
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
			show(list, 0);
			cout << endl;
			break;

		case 7:
			if (isEmpty(list)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				cout << "Podaj pozycje : " << endl;
				cin >> position;
				while (position < 0 || position > list.counter) {
					cout << "Podaj pozycje jeszcze raz : " << endl;
					cin >> position;
				}
				if (position == 1) {
					delete_head(list);
				}
				else if (position == list.counter) {
					delete_tail(list);
				}
				else {
					delete_position(list, position);
				}
				cout << "Usunieto element z " << position << " pozycji" << endl;
			}
			show(list, 0);
			cout << endl;
			break;

		case 8:
			cout << "Lista od poczatku do konca : " << endl;
			show(list, 0);
			cout << endl;
			break;

		case 9:
			cout << "Lista od konca do poczatku : " << endl;
			show(list, 1);
			cout << endl;
			break;


		case 10:
			if (isEmpty(list)) {
				cout << "Lista jest pusta!" << endl;
			}
			else {
				min(list);
			}
			cout << endl;
			break;

		case 11:
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

		case 12:
			system("pause");
			return EXIT_SUCCESS;
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}
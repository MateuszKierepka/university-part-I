#include <iostream>

struct element {
	int number;
	element* next;
};

int isEmpty(element* stack);
void push(element* stack, int value);
int pop(element* stack);
int top(element* stack);

int funkcja(element* stack) {
	int podzielnychPrzez2 = 0;
	element temp;

	while (!isEmpty(stack)) {
		int el = top(stack);
		push(&temp, el);

		if (el % 2 == 0) {
			podzielnychPrzez2++;
		}

		pop(stack);
	}

	while (!isEmpty(&temp)) {
		int el = top(&temp);
		push(stack, el);
		pop(&temp);
	}
	return podzielnychPrzez2;
}

int main(){

}

#include <iostream>

struct dwukierunkowaCykliczna {
	int number;
	dwukierunkowaCykliczna* prev;
	dwukierunkowaCykliczna* next;
};

int funkcja(dwukierunkowaCykliczna* biezacy, int* czypusta) {
	if (biezacy == nullptr) {
		*czypusta = 0;
		return 0;
	}
	
	*czypusta = 1;
	int min = biezacy->number;
	dwukierunkowaCykliczna* temp = biezacy->next;

	while (temp != nullptr) {
		if (temp->number < min) {
			min = temp->number;
		}
		temp = temp->next;
	}
	return min;
}

int main(){
	return 0;
}

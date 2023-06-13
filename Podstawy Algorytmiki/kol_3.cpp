#include <iostream>

struct jednokierunkowaCykliczna {
	int number;
	jednokierunkowaCykliczna* next;
};

int funkcja(jednokierunkowaCykliczna* biezacy, int* czypusta) {
	if (biezacy == nullptr) {
		*czypusta = 0;
		return 0;
	}

	*czypusta = 1;
	int max = biezacy->number;
	jednokierunkowaCykliczna* temp = biezacy->next;

	while (temp != nullptr) {
		if (temp->number > max) {
			max = temp->number;
		}
		temp = temp->next;
	}
	return max;
}

int main(){
	return EXIT_SUCCESS;
}

#include <iostream>

using namespace std;

//zad_1
struct element {
    int character;
    element* next;
};

struct kolejka {
    element* head;
    element* tail;
};

int isEmpty(kolejka* k);
void attach(kolejka* k, int x);
int detache(kolejka* k);
int first(kolejka* k);

int funkcja(kolejka* k) {
    kolejka temp;
    int podzielnePrzez3 = 0;

    while (!isEmpty(k)) {
        int el = first(k);
        attach(&temp, el);

        if (el % 3 == 0) {
            podzielnePrzez3++;
        }

        detache(k);
    }

    while (!isEmpty(&temp)) {
        int el = first(&temp);
        attach(k, el);
        detache(&temp);
    }

    return podzielnePrzez3;
}

//zad_2
struct dwukierunkowaCykliczna {
    int number;
    dwukierunkowaCykliczna* prev;
    dwukierunkowaCykliczna* next;
};

int function(dwukierunkowaCykliczna* biezacy, int* czypusta) {
    if (biezacy == nullptr) {
        *czypusta = 0;
        return EXIT_FAILURE;
    }

    *czypusta = 1;
    int min = biezacy->number;
    dwukierunkowaCykliczna* temp = biezacy->next;

    while (temp != biezacy) {
        if (temp->number < min) {
            min = temp->number;
        }
        temp = temp->next;
    }
    return min;
}

int main() {

    system("pause");
    return EXIT_SUCCESS;
}
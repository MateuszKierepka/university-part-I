#include <iostream>

using namespace std;

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

int main() {
    system("pause");
    return 0;
}

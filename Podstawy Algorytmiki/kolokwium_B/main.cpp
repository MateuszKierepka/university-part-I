#include <iostream>

using namespace std;

//zad_1
struct stos{
    int number;
    stos* next;
};

int isEmpty(stos* w);
void push(stos*& w, int x);
int pop(stos*& w);
int first(stos* w);

int funkcja(stos* w){
    int liczba_parzystych = 0;
    stos* temp;

    while (!isEmpty(w)){
        int el = first(w);
        push(temp, el);

        if (el % 2 == 0){
            liczba_parzystych++;
        }

        pop(w);
    }

    while(!isEmpty(temp)){
        int el = first(temp);
        push(w, el);
        pop(temp);
    }

    return liczba_parzystych;
}

//zad_2
struct jednokierunkowaCykliczna{
    int number;
    jednokierunkowaCykliczna* next;
};

int function(jednokierunkowaCykliczna* biezacy, int* czypusta){
    if(biezacy == nullptr){
        *czypusta = 0;
        return EXIT_FAILURE;
    }

    *czypusta = 1;
    int max = biezacy->number;
    jednokierunkowaCykliczna* temp = biezacy->next;

    while (temp != nullptr){
        if (temp->number > max){
            max = temp->number;
        }
        temp = temp->next;
    }

    return max;
}


int main() {

    system("pause");
    return EXIT_SUCCESS;
}

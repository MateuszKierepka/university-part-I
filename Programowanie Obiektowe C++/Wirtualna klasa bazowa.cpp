#include <iostream>

using namespace std;

class A {
public:
    void pokaz()
    {
        cout<<"Czesc z klasy A \n";
    }
};

class B : public virtual A{

};

class C : public virtual A{

};

class D : public B, public C{

};

int main() {
    ::setlocale(LC_ALL,"");
    D obiekt;
    obiekt.pokaz();
}

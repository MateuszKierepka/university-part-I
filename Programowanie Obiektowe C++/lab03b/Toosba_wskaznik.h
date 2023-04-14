#ifndef TOSOBA_WSKAZNIK_TOOSBA_WSKAZNIK_H
#define TOSOBA_WSKAZNIK_TOOSBA_WSKAZNIK_H
#include <string>

using namespace std;

struct Tdata{
    int d, m, r;
};

class Toosba_wskaznik {
private:
    string imie;
    string nazwisko;
    Tdata data;

public:

    //Wykorzystując klasę Tosoba utwórz obiekt za pomocą operatora new.
    // Wykonaj operacje na obiekcie z pomocą wskaźnika. Usuń wskaźnik za pomocą operatora delete.

    Toosba_wskaznik(); //konstruktor domyślny
    Toosba_wskaznik(int rok);
    ~Toosba_wskaznik(); //destruktor

    void wczytaj();

    void wyswietl();
    void wyswietl(int rok);

    void info();
    void info(int rok);
};

#endif //TOSOBA_WSKAZNIK_TOOSBA_WSKAZNIK_H

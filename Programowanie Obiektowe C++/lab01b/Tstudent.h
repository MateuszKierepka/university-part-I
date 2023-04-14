#ifndef TSTUDENT_TSTUDENT_H
#define TSTUDENT_TSTUDENT_H

class Tstudent {
private:
    char imie[20], nazwisko[20];
    int egzamin[3];
public:
    void wczytaj();
    float srednia();
    void wyswietl();
};

#endif //TSTUDENT_TSTUDENT_H

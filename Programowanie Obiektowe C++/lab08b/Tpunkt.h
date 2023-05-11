#ifndef LAB08B_TPUNKT_H
#define LAB08B_TPUNKT_H

class Tkolo;

class Tpunkt {
    float x, y;

public:
    Tpunkt();
    Tpunkt(float x, float y);
    ~Tpunkt();

    void ruch(float x_a, float y_b);
    float getX();
    float getY();

    friend bool nalezy(Tpunkt *punkt, Tkolo *kolo);
};

class Tkolo {
    float r;

public:
    Tkolo();
    Tkolo(float r);
    ~Tkolo();

    float getR();

    friend bool nalezy(Tpunkt *punkt, Tkolo *kolo);
};

#endif //LAB08B_TPUNKT_H

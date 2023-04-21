#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int make_hash(char s, int off,int p, int exp){
    int hash = (((int)s) - off)*pow(p,exp);
    return hash;
}

int update_hash(int hash, char s_prev, char s_next, int off,int p, int exp){
    int u_hash=hash - ((int)s_prev-off)*pow(p,exp);
    u_hash = u_hash*p;
    u_hash = u_hash +((int)s_next-off);
    return u_hash;
}

void kr(string pattern, string text, int p, int off){
    bool spr= true;
    int lenP = pattern.length();
    int lenT = text.length();
    int hashP=0;
    int hashT = 0;
    for(int i=0; i<lenP; i++){
        hashP = hashP+ make_hash(pattern[i], off, p,lenP-i-1);
        hashT = hashT+ make_hash(text[i], off, p,lenP-i-1);
    }
    for(int j=0, i=lenP; i<=lenT; i++, j++){
        if(hashP == hashT){
            int k=0;
            while(k < lenP && pattern[k] == text[j+k]){
                k++;
            }
            if(k == lenP){
                cout<<j<<" ";
                spr=false;
            }
        }
        if(i < lenT){
            hashT = update_hash(hashT,text[j],text[i], off, p,lenP-1);
        }
    }
    if(spr){
        cout<<"-1";
    }
}

int main() {
    string sciezka, linia, wz;
    ifstream plik;
    sciezka="C:\\Users\\Mateusz\\Desktop\\Studia\\SEMESTR-II\\university-part-I\\Podstawy Algorytmiki\\lab06\\tekst.txt";
    plik.open(sciezka);
    if(plik.is_open()){
        plik >> wz;
        cout<<"Wzorzec : "<<wz<<endl;
        int i=2; //w pierwszej linii znajduje sie wzorzec
        while (!plik.eof()){//flaga ktora mowi ze napotkano koniec pliku
            plik >> linia;
            cout<<"Linijka nr "<<i<<" : ";
            kr(wz,linia,2,0);
            i++;
            cout<<endl;
        }
        plik.close();
    }
    else {
        cout << "Nie mozna otworzyc pliku...";
    }
    return 0;
}

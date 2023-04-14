#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int make_hash(char s, int off, int p, int exp){
    int hash=((int)s-off)*pow(p,exp);

    return hash;
}

int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp){
    int u_hash = hash-((int)s_prev-off)*pow(p,exp);
    u_hash*=p;
    u_hash+=((int)s_next-off);

    return u_hash;
}

bool kr(string pattern, string tekst,int p, int off){
    bool result= false;
    int hashP=0;
    int hashT=0;
    int i=0;
    while(i<pattern.length()){
        hashP=hashP+make_hash(pattern[i],off,p,pattern.length()-i-1);
        hashT=hashT+make_hash(tekst[i],off,p, pattern.length()-i-1);
        i++;
    }
    i=pattern.length();
    int j=0;

    while(i<=tekst.length()){
        if(hashP==hashT){
            int k=0;
            while(k<pattern.length() && pattern[k]==tekst[j+k]) k++;
            if(k==pattern.length()){
                cout<<j<<" ";
                result= true;
            }
        }
        if(i<tekst.length()){
            hashT= update_hash(hashT,tekst[j],tekst[i],off,p,pattern.length()-1);
        }
        i++;
        j++;
    }
    return result;
}

int main() {
    string wzorzec, tekst;
    int alfabet, podstawa;

    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, wzorzec);
    cout<<"Podaj alfabet: "<<endl;
    cin>>alfabet;
    cout<<"Podaj podstawe: "<<endl;
    cin>>podstawa;

    string sciezka,linia,pomoc;
    fstream plik;
    plik.open("tekst.txt");
    while(getline(plik,linia)){
        if(kr(wzorzec,linia,podstawa,alfabet)){
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    plik.close();
    return 0;
}

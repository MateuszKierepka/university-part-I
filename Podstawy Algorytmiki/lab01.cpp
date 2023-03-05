//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//void przydzielPamiec1D(int *&tab, int n){
//    tab = new int[n];}
//
//void przydzielPamiec2D(int **&tab, int w, int k){
//    tab = new int*[w];
//    for(int i=0; i<w; i++){
//        tab[w]= new int[k];}}
//
//void wypelnijTablice1D(int *tab, int n, int a, int b){
//    srand(time(NULL));
//    int i, liczba;
//    for(i=0; i<n; i++){
//        int liczba = rand()%(b-a+1)+a;
//        tab[i]=liczba;}}
//
//void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
//    int i, j, liczba;
//    for(i=0; i<w; i++){
//        for(j=0; j<k; j++){
//            liczba = rand()%(b-a+1)+a;
//            tab[i][j] = liczba;}}}
//
//void usunTablice1D(int *&tab){
//    delete [] tab;}
//
//void wyswietl1D(int* tab, int n){
//    for(int i=0; i<n; i++){
//        cout<<tab[i]<<" ";
//    }
//    cout<<"\n";}
//
//void usunTablice2D(int **&tab, int w){
//    int i;
//    for(i=0; i<w; i++){
//        delete [] tab[i];}
//    delete [] tab;}
//
//void wyswietl2D(int** tab, int w, int k){
//    int i, j;
//    for(i=0; i<w; i++){
//        for(j=0; j<k; j++){
//            cout<<tab[i][j]<<"\t";
//        }
//        cout<<"\n";}}
//
//int main(int argc, const char * argv[]) {
//        int n, w, k, a, b;
//        int *tab1 = nullptr;
//        cout << "Podaj n: " << endl;
//        cin >> n;
//        cout << "Podaj w: " << endl;
//        cin >> w;
//        cout << "Podaj k: " << endl;
//        cin >> k;
//        int **tab2 = nullptr;
//
//        przydzielPamiec1D(tab1, n);
//        przydzielPamiec2D(tab2, w, k);
//
//        cout << "Podaj a: " << endl;
//        cin >> a;
//        cout << "Podaj b: " << endl;
//        cin >> b;
//
//        wypelnijTablice1D(tab1, n, a, b);
//        wypelnijTablice2D(tab2, w, k, a, b);
//
//        wyswietl1D(tab1, n);
//        wyswietl2D(tab2, w, k);
//
//        usunTablice1D(tab1);
//        usunTablice2D(tab2, w);
//    return 0;}

#include <iostream>
#include <ctime>

using namespace std;

void min(int n, int a, int b){
    int tab[n], minimalna;
    srand(time(NULL));
    for(int i=0; i<n; i++){
        tab[i] = rand()%(b-a+1)+a;}
    minimalna = tab[0];
    for(int i=0; i<n; i++){
        if(tab[i] < minimalna){
            minimalna = tab[i];}
    }
    cout<<"Minimalna liczba to "<<minimalna<<endl;
}



int main(int argc, const char * argv[]) {
int wybor=0;
while(wybor==0){
cout<<"Wybierz program:\n1-Minimalny element\n2-Zliczanie w tablicy\n3-Maksymalny element\n4-Srednia"<<endl;
cin>>wybor;}

switch(wybor){
        case 1:{
        int n=0, a, b;
        while(n<=0){
            cout<<"Podaj n:"<<endl;
            cin>>n;}
        cout<<"Podaj a i b:"<<endl;
        cin>>a>>b;
        min(n, a, b);}

        case 2:{
        
        }
}

return 0;}
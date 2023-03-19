#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void sortowanieBabelkowe(int* tab, int n, int tryb){
    int a, b;
    cout<<"Podaj a i b\n";
    cin>>a>>b;
    tab = new int[n];
    srand(time(nullptr));
    for(int i=0; i<n; i++){
        int liczba = rand()%(b-a+1)+a;
        tab[i] = liczba;}
    cout<<"Tablica przed posortowaniem : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}

    if(tryb == 1) {
        int i = n - 1;
        while (i > 0) {
            int j = 0;
            while (j < i) {
                if (tab[j] > tab[j + 1]) {
                    swap(tab[j], tab[j + 1]);
                }
                j++;
            }
            i--;}}

    else if(tryb == 2){
        int i = n-1;
        while(i > 0) {
            int j = 0;
            while (j < i) {
                if (tab[j] < tab[j + 1]) {
                    swap(tab[j], tab[j + 1]);
                }
                j++;
            }
            i--;}}

    cout<<"\nTablica po posortowaniu : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}
    delete [] tab;}

void sortowaniePrzezWybor(int* tab, int n, int tryb){
    int a, b;
    cout<<"Podaj a i b\n";
    cin>>a>>b;
    tab = new int[n];
    srand(time(nullptr));
    for(int i=0; i<n; i++){
        int liczba = rand()%(b-a+1)+a;
        tab[i] = liczba;}
    cout<<"Tablica przed posortowaniem : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}

    if(tryb == 1) {
        int i = n - 1;
        while (i > 0) {
            int ind = 0;
            int j = 1;
            while (j <= i) {
                if (tab[j] > tab[ind]) {
                    ind = j;
                }
                j++;
            }
            swap(tab[i], tab[ind]);
            i--;}}

    else if(tryb == 2){
        int i = n - 1;
        while (i > 0) {
            int ind = 0;
            int j = 1;
            while (j <= i) {
                if (tab[j] < tab[ind]) {
                    ind = j;
                }
                j++;
            }
            swap(tab[i], tab[ind]);
            i--;}}

    cout<<"\nTablica po posortowaniu : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}
    delete [] tab;}

void sortowaniePrzezWstawianie(int* tab, int n, int tryb){
    int a, b;
    cout<<"Podaj a i b\n";
    cin>>a>>b;
    tab = new int[n];
    srand(time(nullptr));
    for(int i=0; i<n; i++){
        int liczba = rand()%(b-a+1)+a;
        tab[i] = liczba;}
    cout<<"Tablica przed posortowaniem : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}

    if(tryb == 1){
        int i = n -2;
        while(i >= 0){
            int j = i;
            int temp = tab[j];
            while(temp > tab[j+1] && j < n-1){
                tab[j] = tab[j+1];
                j++;
            }
            tab[j] = temp;
            i--;}}

    else if(tryb == 2){
        int i = n -2;
        while(i >= 0){
            int j = i;
            int temp = tab[j];
            while(temp < tab[j+1] && j < n-1){
                tab[j] = tab[j+1];
                j++;
            }
            tab[j] = temp;
            i--;}}

    cout<<"\nTablica po posortowaniu : ";
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";}
    delete [] tab;}

void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol){
    int a, b;
    cout<<"Podaj a i b\n";
    cin>>a>>b;
    tab = new int*[w];
    for(int i=0; i<w; i++){
        tab[i] = new int[k];
    }
    srand(time(nullptr));
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
        int liczba = rand()%(b-a+1)+a;
        tab[i][j] = liczba;}}
    cout<<"Tablica przed posortowaniem :\n";
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout<<tab[i][j]<<"  ";}
    cout<<"\n";}

    if(0 < nrKol < k){
        if(tryb == 1){
            int i = nrKol - 1;
            int ind = i;
            while(i > 0){
                int j = 0;
                while(j < i){
                    if(tab[j][ind] > tab[j+1][ind]){
                        swap(tab[j][ind], tab[j+1][ind]);}
                    j++;}
                i--;
            }
            }

        else if(tryb == 2){
            int i = nrKol - 1;
            int ind = nrKol - 1;
            while(i > 0){
                int j = 0;
                while(j < i){
                    if(tab[j][ind] > tab[j+1][ind]){
                        swap(tab[j][ind], tab[j+1][ind]);}
                    j++;}
                i--;
            }
        }
        }

    cout<<"Tablica po posortowaniu :\n";
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout<<tab[i][j]<<"  ";
        }
        cout<<"\n";
    }
    delete [] tab;
}

int main() {
    while(true){
    int wybor;
    cout<<"Wybierz program :\n1 - Sortowanie babelkowe\n2 - Sortowanie przez wybor\n3 - Sortowanie przez wstawianie\n4 - Sortowanie tablicy dwuwymiarowej\n5 -  Wyjscie\n";
    cin>>wybor;
    switch (wybor) {
        case 1: {
            cout << "Sortowanie Babelkowe...\n";
            int n, tryb;
            int *tab = nullptr;
            cout << "Podaj n :\n";
            cin >> n;
            cout << "Podaj tryb :\n1 - rosnaco\n2 - malejaco\n";
            cin >> tryb;
            sortowanieBabelkowe(tab, n, tryb);
            break;
        }

        case 2: {
            cout << "Sortowanie Przez Wybor...\n";
            int n, tryb;
            int *tab = nullptr;
            cout << "Podaj n :\n";
            cin >> n;
            cout << "Podaj tryb :\n1 - rosnaco\n2 - malejaco\n";
            cin >> tryb;
            sortowaniePrzezWybor(tab, n, tryb);
            break;
        }

        case 3: {
            cout << "Sortowanie Przez Wstawianie...\n";
            int n, tryb;
            int *tab = nullptr;
            cout << "Podaj n :\n";
            cin >> n;
            cout << "Podaj tryb :\n1 - rosnaco\n2 - malejaco\n";
            cin >> tryb;
            sortowaniePrzezWstawianie(tab, n, tryb);
            break;
        }

        case 4: {
            cout << "Sortowanie tablicy dwuwymiarowej...\n";
            int w, k, tryb, nrKol;
            int **tab = nullptr;
            cout << "Podaj liczbe wierszy i liczbe kolumn : \n";
            cin >> w >> k;
            cout << "Podaj tryb :\n1 - rosnaco\n2 - malejaco\n";
            cin >> tryb;
            cout << "W ktorej kolumnie posortowac dane ?\n";
            cin >> nrKol;
            sortowanieBabelkowe2D(tab, w, k, tryb, nrKol);
            break;
        }

        case 5: {
            return EXIT_SUCCESS;
        }

        default:
            cout << "blad danych";
            break;
    }
            }}
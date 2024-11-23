// Fie un vect cu n elem int. Se cere:
// a) produsul elementelor care au ult cifra nenula
// b) sa se afle daca vectorul este descresc
// c) care e cel mai mic elem din vect? dar din prima jum?

#include <iostream>
#include <cmath>

using namespace std;

int n, v[100], z;

void dei_afisare(int st, int dr){
     int m, x1, x2;
     if(st == dr){
        cout << v[st] << " ";
     } else{
        m = (st + dr) / 2;
        dei_afisare(st, m);
        dei_afisare(m + 1, dr);
     }
}

void dei_citire(int st, int dr){
    int m;
    if(st == dr){
        cout << "Numarul de pe pozitia " << st << ": ";
        cin >> v[st];
    }
    else{
        m = (st + dr) / 2;
        dei_citire(st, m);
        dei_citire(m + 1, dr);
    }
}

int dei_prod(int st, int dr){
    if(st == dr){
        return v[st] % 10 ? v[st] : 1;
    } 
    else{
        int m = (st + dr) / 2;
        return dei_prod(st, m) * dei_prod(m + 1, dr);
    }
}

int dei_descresc(int st, int dr){
    if(st >= dr - 1)
         return v[st] >= v[dr];
    else{
        int m = (st + dr) / 2;
        return dei_descresc(1, m) && dei_descresc(m, dr);
    }
}

int dei_min(int st, int dr){
    if(st >= dr - 1)
        return min(v[st], v[dr]);
    else{
        int m = (st + dr) / 2;
        return min(dei_min(st, m), dei_min(m + 1, dr));
    }
}

int main(){
    cout << "n = "; cin >> n;
    dei_citire(1, n);
    cout << "Vectorul initial: "; 
    dei_afisare(1, n);

    // a
    cout << "\nProdusul elementelor ce au ultima cifra nenula este: " << dei_prod(1, n);
    
    // b
    if(dei_descresc(1, n)) cout << "\nVectorul este ordonat descrecator.";
    else cout << "\nVectorul nu este ordonat descrecator.";

    // c
    cout << "\nCel mai mic element din vector este: " << dei_min(1, n);
    cout << "\nCel mai mic element din prima jum a vectorului este: " << dei_min(1, n / 2);

    return 0;
}

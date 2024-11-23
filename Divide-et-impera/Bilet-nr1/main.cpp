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

int dei_suma(int st, int dr){
    if(st == dr){
        if(v[st] % 2 == 0 && v[st] > 9 && v[st] < 100) return v[st];
        else return 0;
    } 
    else{
        int m = (st + dr) / 2;
        return dei_suma(st, m) + dei_suma(m + 1, dr);
    }
}

int dei_egale(int st, int dr){
    // verfica daca toate sunt egale
    if(st >= dr - 1)
        return v[st] == v[dr];
    else{
        int m = (st + dr) / 2;
        return dei_egale(1, m) && dei_egale(m + 1, dr);
}    
}

int dei_max(int st, int dr){
    if(st >= dr - 1) 
        return max(v[st], v[dr]);
    else{
        int m = (st + dr) / 2;
        return max(dei_max(st, m), dei_max(m + 1, dr));
    }
}

int dei_imp(int st, int dr){
    // verifica daca elem e imp si indexul e par
    if(st == dr) 
        return (v[st] % 2 && st % 2 == 0) ?  1 : 0;
    else{
        int m = (st + dr) / 2;
        return dei_imp(st, m) + dei_imp(m + 1, dr);
    }
}

int dei_cresc(int st, int dr){
    // verifica daca sunt crescatoare
    if(st >= dr - 1)
        return v[st] < v[dr];
    else{
        int m = (st + dr) / 2;
        return dei_cresc(st, m) && dei_cresc(m, dr);
    }
}

int main(){
    cout << "n = "; cin >> n;
    dei_citire(1, n);
    cout << "\nVectorul initial: "; 
    dei_afisare(1, n);

    // a
    cout << "\nSuma elementelor pare de doua cifre este: " << dei_suma(1, n);

    // b
    if(dei_egale(1, n)) cout << "\nToate elementele sunt egale intre ele.";
    else cout << "\nNu toate elementele sunt egale inte ele.";

    // c
    cout << "\nMaximul elementelor este: " << dei_max(1, n);
    cout << "\nMaximul elementelor din a doua jumatate este: " << dei_max(n / 2, n);

    // d
    cout << "\nIn total sunt " << dei_imp(1, n) << " numere impare pe pozitii pare.";

    // suplimentar
    if(dei_cresc(1, n)) cout << "\nElementele sunt ordonate crescator.";
    else cout << "\nElementele nu sunt ordonate crescator.";

    return 0;
}

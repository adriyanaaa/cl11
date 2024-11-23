#include <iostream>
#include <cmath>

using namespace std;

int n, v[100], z, nr;

int cautare_bin(int st, int dr){
    int m = (st + dr) / 2;
    if(v[m] == nr) return m;
    else if(st < dr){
        if(m > nr) return cautare_bin(m + 1, dr);
        else return cautare_bin(st, m - 1);
    }
    else return 0;
}

int main(){
    cout << "n = "; cin >> n;
    cout << "Introdu cele " << n << " elemente in ord descresc: " << endl;
    for(int i = 1; i <= n; i++){
        cout << "Numarul de pe pozitia " << i << ": ";
        cin >> v[i];
    }
    cout << "Introdu numarul pe care doresti sa il cauti: ";
    cin >> nr;
    int poz = cautare_bin(1, n);

    if(poz) cout << "Numarul introdus se afla pe pozitia " << poz;
    else cout << "Numarul introdus nu se afla in vector.";
    return 0;
}

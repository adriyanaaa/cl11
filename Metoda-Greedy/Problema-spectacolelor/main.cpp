#include <iostream>
#include <fstream>
using namespace std;

ifstream in("./spectacol.in");
ofstream out("./spectacol.out");

int main() {
    int n, i, ora, minut;
    int a[101], b[101], nr[101], sortat, t, k;

    in >> n;
    for (i = 1; i <= n; i++) {
        nr[i] = i;
        in >> ora >> minut;
        a[i] = ora * 60 + minut;
        in >> ora >> minut;
        b[i] = ora * 60 + minut;
    }

    do {
        sortat = 0;
        for (i = 1; i < n; i++) {
            if (b[nr[i]] > b[nr[i + 1]]) {
                t = nr[i];
                nr[i] = nr[i + 1];
                nr[i + 1] = t;
                sortat = 1;
            }
        }
    } while (sortat == 1);

    k = 1;
    out << nr[1] << ' ';
    for (i = 2; i <= n; i++) {
        if (a[nr[i]] >= b[nr[k]]) {
            out << nr[i] << ' ';
            k = i;
        }
    }

    in.close();
    out.close();
    return 0;
}

#include <iostream>
#include "Solucionador.h"

using namespace std;

int main() {
    Solucio sol;
    Solucionador algBack;

    cout << "Mostrant tauler inicial..." << endl;
    sol.mostra();

    bool encertat = algBack.solucionar(sol);

    if (encertat) {
        cout << endl << "Mostrant tauler final..." << endl;
        sol.mostra();
    } else {
        cout << endl << "No té solució" << endl;
    }

    return 0;
}

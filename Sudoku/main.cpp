#include "Solucionador.h"

using namespace std;

int main(int argn, char** args) {

    if (argn < 2) {
        cout << "Nombre de paràmetres incorrecte" << endl;
        exit(1);
    }

    Solucio sol(args[1]);
    Solucionador algBack;

    cout << "✔ | Mostrant tauler inicial..." << endl;
    sol.mostra();

    bool encertat = algBack.solucionar(sol);

    if (encertat) {
        cout << endl << "✔ | Mostrant tauler final..." << endl;
        sol.mostra();
    } else {
        cout << endl << "✘ | No té solució" << endl;
    }

    return 0;
}

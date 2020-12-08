#include "Solucionador.h"

Solucionador::Solucionador() {
    Encertat = false;
}

bool Solucionador::solucionar(Solucio& sol) {
    actual = sol;
    cout << endl << "✔ | Buscant una solució..." << endl;
    backtracking(0);
    sol = actual;
    return Encertat;
}

void Solucionador::backtracking(unsigned pos) {
    Candidats can = actual.InicialitzarCandidats(pos);
    while (not can.Fi() and not Encertat) {
        if (actual.Acceptable(pos, can)) {
            actual.AnotarCandidat(pos, can);
            if (not actual.SolucioCompleta()) {
                backtracking(pos+1);
                if (not Encertat) {
                    actual.DesanotarCandidat(pos);
                }
            } else {
                Encertat = true;
            }
        }
        can.Seguent();
    }
}


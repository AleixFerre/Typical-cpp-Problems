#include "Solucio.h"

Solucio::Solucio() {
    tauler = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    casellesRestants = 0;
    mida = tauler.size();

    for (unsigned i=0; i < mida; i++) {
        for (unsigned j=0; j < mida; j++) {
            if (tauler[i][j] == 0) {
                casellesRestants++;
            }
        }
    }
}

Candidats Solucio::InicialitzarCandidats(unsigned pos) const {
    unsigned valor = getValorPosicio(pos);

    if (valor == 0) {
        return Candidats(mida);
    } else {
        // si el valor està posat, no hem de comprovar res, només hem de passar un bucle per passar al seguent
        return Candidats(1, 0);
    }
}

bool Solucio::Acceptable(unsigned pos, const Candidats& can) const {

    if (getValorPosicio(pos) != 0) {
        return true;
    }

    // Si no està posat, mirem si el podem posar.

    return true; // TODO

}

bool Solucio::SolucioCompleta() const {
    return casellesRestants == 0;
}

void Solucio::AnotarCandidat(unsigned pos, const Candidats& can) {
    if (getValorPosicio(pos) == 0) {
        setValorPosicio(pos, can.Actual());
        casellesRestants--;
    }
}

void Solucio::DesanotarCandidat(unsigned pos) {
    if (getValorPosicio(pos) == 0) {
        setValorPosicio(pos, 0);
        casellesRestants++;
    }
}

void Solucio::mostra() const {
    for (unsigned i = 0; i < mida; i++) {
        if (i%3 == 0) {
            mostrarLiniaDelimitant();
        }
        mostrarLinia(tauler[i]);
    }
    mostrarLiniaDelimitant();
}

unsigned Solucio::getValorPosicio(unsigned index) const {
    return tauler[index % mida][index / mida];
}

void Solucio::setValorPosicio(unsigned index, unsigned val) {
    tauler[index % mida][index / mida] = val;
}

void Solucio::mostrarCasella(unsigned num) const {
    if (num == 0) {
        cout << "· ";
    } else {
        cout << num << " ";
    }
}

void Solucio::mostrarLiniaDelimitant() const {
    cout << "x-------x-------x-------x" << endl;
}

void Solucio::mostrarLinia(const vector<unsigned>& t) const {
    cout << "| ";
    for (int i = 0; i < 3; i++) {
        mostrarCasella(t[i]);
    }
    cout << "| ";
    for (int i = 3; i < 6; i++) {
        mostrarCasella(t[i]);
    }
    cout << "| ";
    for (int i = 6; i < 9; i++) {
        mostrarCasella(t[i]);
    }
    cout << "|" << endl;
}

#include "Solucio.h"
#include <fstream>

Solucio::Solucio() {
    mida = 9;
    tauler = vector<vector<unsigned>>(mida, vector<unsigned>(mida, 0));
    esPodenTocar = vector<vector<bool>>(mida, vector<bool>(mida, false));
    casellesRestants = mida * mida;
}

Solucio::Solucio(string nomFitxer) {

    ifstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.fail()) {
        cout << "No es pot llegir el fitxer " << nomFitxer << endl;
        exit(1);
    }

    // Pre: sudoku mida 9x9 i fitxer formatat correctament
    mida = 9;
    for (unsigned i = 0; i < mida; i++) {
        tauler.push_back(vector<unsigned>());
        esPodenTocar.push_back(vector<bool>());
        for (unsigned j = 0; j < mida; j++) {
            unsigned val;
            fitxer >> val;
            tauler[i].push_back(val);
            esPodenTocar[i].push_back(val == 0);
        }
    }

    fitxer.close();
    casellesRestants = mida*mida;

}

Candidats Solucio::InicialitzarCandidats(unsigned pos) const {
    unsigned valor = getValorPosicio(pos);

    if (valor == 0) {
        return Candidats(mida);
    } else {
        // Si el valor està posat, no hem de comprovar res,
        // només hem de passar un bucle per passar a la següent casella
        return Candidats();
    }
}

bool Solucio::Acceptable(unsigned pos, const Candidats& can) const {

    if (not pucPosarNum(pos)) {
        return true;
    }

    // Si no està posat, mirem si el podem posar.
    // Mirem fila, mirem columna i mirem quadrat
    return not existeixFilaColumna(pos, can.Actual()) and
           not existeixQuadrat(pos, can.Actual());
}

bool Solucio::SolucioCompleta() const {
    return casellesRestants == 0;
}

void Solucio::AnotarCandidat(unsigned pos, const Candidats& can) {
    if (pucPosarNum(pos)) {
        setValorPosicio(pos, can.Actual());
    }
    casellesRestants--;
}

void Solucio::DesanotarCandidat(unsigned pos) {
    if (pucPosarNum(pos)) {
        setValorPosicio(pos, 0);
    }
    casellesRestants++;
}

void Solucio::mostra() const {
    for (unsigned i = 0; i < mida; i++) {
        if (i%3 == 0) {
            mostrarLiniaDelimitant();
        }
        mostrarLinia(tauler[i], esPodenTocar[i]);
    }
    mostrarLiniaDelimitant();
}

void Solucio::mostrarCasella(unsigned num, bool esInicial) const {
    if (num == 0) {
        cout << "· ";
    } else if (esInicial) {
        cout << "\033[93m" << num << "\033[39m ";
    } else {
        cout << num << " ";
    }
}

void Solucio::mostrarLiniaDelimitant() const {
    cout << "x-------x-------x-------x" << endl;
}

void Solucio::mostrarLinia(const vector<unsigned>& t, const vector<bool>& v) const {
    for (int k = 0; k < 3; k++) {
        cout << "| ";
        int inc = k*3;
        for (int i = inc; i < inc+3; i++) {
            mostrarCasella(t[i], not v[i]);
        }
    }
    cout << "|" << endl;
}

unsigned Solucio::getValorPosicio(unsigned index) const {
    return tauler[index % mida][index / mida];
}

void Solucio::setValorPosicio(unsigned index, unsigned val) {
    tauler[index % mida][index / mida] = val;
}

bool Solucio::pucPosarNum(unsigned index) const {
    return esPodenTocar[index % mida][index / mida];
}

bool Solucio::existeixFilaColumna(unsigned pos, unsigned val) const {

    unsigned fila = pos % mida, columna = pos / mida;

    for (unsigned i = 0; i < mida; i++) {
        if (tauler[fila][i] == val or tauler[i][columna] == val) {
            return true;
        }
    }

    return false;
}

bool Solucio::existeixQuadrat(unsigned pos, unsigned val) const {
    unsigned fila = pos % mida, columna = pos / mida,
             principiFila = fila - fila % 3, principiColumna = columna - columna % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tauler[i + principiFila][j + principiColumna] == val) {
                return true;
            }
        }
    }

    return false;
}


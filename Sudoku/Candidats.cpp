#include "Candidats.h"

Candidats::Candidats() {
    mida = 0;
    index = 0;
}

Candidats::Candidats(unsigned _mida) {
    mida = _mida;
    index = 1;
}

Candidats::Candidats(unsigned _mida, unsigned _index) {
    mida = _mida;
    index = _index;
}

unsigned Candidats::Actual() const {
    return index;
}

bool Candidats::Fi() const {
    return index > mida;
}

void Candidats::Seguent() {
    index++;
}

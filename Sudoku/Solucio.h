#ifndef SOLUCIO_H
#define SOLUCIO_H
#include "Candidats.h"
#include <iostream>
#include <vector>

using namespace std;

class Solucio {
  public:
    Solucio();
    // Solucio(string nomFitxer);

    Candidats InicialitzarCandidats(unsigned pos) const;
    bool Acceptable(unsigned pos, const Candidats& can) const;
    bool SolucioCompleta() const;

    void AnotarCandidat(unsigned pos, const Candidats& can);
    void DesanotarCandidat(unsigned pos);

    void mostra() const;

  private:
    vector<vector<unsigned>> tauler;
    unsigned casellesRestants, mida;

    void mostrarCasella(unsigned num) const;
    void mostrarLinia(const vector<unsigned>& t) const;
    void mostrarLiniaDelimitant() const;

    unsigned getValorPosicio(unsigned index) const;
    void setValorPosicio(unsigned index, unsigned val);
};

#endif // SOLUCIO_H

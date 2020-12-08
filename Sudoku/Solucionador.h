#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"

class Solucionador {
  public:
    Solucionador();
    bool solucionar(Solucio& sol);

  private:
    Solucio actual;
    bool Encertat;

    void backtracking(unsigned pos);
};

#endif // SOLUCIONADOR_H

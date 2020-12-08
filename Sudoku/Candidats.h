#ifndef CANDIDATS_H
#define CANDIDATS_H

using namespace std;

class Candidats {
  public:
    Candidats(unsigned _mida);
    Candidats(unsigned _mida, unsigned _index);
    unsigned Actual() const;
    bool Fi() const;
    void Seguent();

  private:
    unsigned index;
    unsigned mida;
};


#endif // CANDIDATS_H

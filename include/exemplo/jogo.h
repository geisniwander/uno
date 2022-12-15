
#include <iostream>
#include <string>

#include "baralho.h"
#include "carta.h"
#ifndef JOGO_H
#define JOGO_H

namespace trabalho {

class Jogo {
    Baralho *b1 = new Baralho;
    BaralhoJogador *bj = new BaralhoJogador(*b1);
    BaralhoJogador *bj2 = new BaralhoJogador(*b1);
    PilhaJogo *pj = new PilhaJogo(*b1);

   public:
    Jogo() {}
    ~Jogo() {
        b1->~Baralho();
        bj->~BaralhoJogador();
        bj2->~BaralhoJogador();
        pj->~PilhaJogo();
    }
    void jogar();
};

}  // namespace trabalho
#endif

#ifndef BARALHO_H
#define BARALHO_H
#include <climits>
#include <random>
#include <vector>

#include "carta.h"

namespace trabalho {

/*---------------COMPOSIÇÃO-------------------*/
class Baralho {
   private:
    std::vector<Carta> baralho;

   public:
    Baralho();
    virtual ~Baralho() = default;
    virtual Carta get_c(long unsigned int i);
    Carta cartas();
    void eraseC(int i);
    long unsigned int get_size();
    long unsigned int random(long unsigned int low, long unsigned int high);
};
/*---------------COMPOSIÇÃO-------------------*/

/*---------------HERANÇA-------------------*/
class BaralhoJogador : public Baralho {
   private:
    std::vector<Carta> baralhoJogador;

   public:
    BaralhoJogador() {}
    BaralhoJogador(Baralho &b);
    virtual ~BaralhoJogador() {}
    virtual Carta get_c(long unsigned int i);
    long unsigned int get_size();
    void eraseCj(long unsigned int i);
    void comprar(Baralho &b, long unsigned int qtd);
    bool verificaVitoria();
};

class PilhaJogo : public Baralho {
   private:
    std::vector<Carta> pilhaJogo;

   public:
    PilhaJogo() {}
    PilhaJogo(Baralho &b);
    virtual ~PilhaJogo() {}
    virtual Carta get_c(long unsigned int i);
    long unsigned int get_size();
    void adicionaCarta(Carta &a);
    void muda_cor(int cor);
};
/*---------------HERANÇA-------------------*/

/*-------SOBRECARGA DE OPERADORES----------*/
std::ostream &operator<<(std::ostream &saida, Baralho &c) {
    for (long unsigned int i = 0; i <= (c.get_size()) - 1; i++) {
        Carta t = c.get_c(i);
        saida << t;
    }
    return saida;
}

std::ostream &operator<<(std::ostream &saida, BaralhoJogador &c) {
    saida << "---------------------------------" << std::endl;
    saida << "Próximo Jogador" << std::endl;
    saida << "Cartas do jogador atual:" << std::endl;
    for (long unsigned int i = 0; i <= (c.get_size()) - 1; i++) {
        Carta t = c.get_c(i);
        saida << "Carta [" << i << "]: " << t;
    }
    return saida;
}

std::ostream &operator<<(std::ostream &saida, PilhaJogo &c) {
    saida << "---------------------------------" << std::endl;
    saida << "Carta da pilha: " << std::endl;
    Carta t = c.get_c(c.get_size() - 1);
    saida << t;
    saida << "---------------------------------" << std::endl;
    return saida;
}
/*-------SOBRECARGA DE OPERADORES----------*/

}  // namespace trabalho
#endif
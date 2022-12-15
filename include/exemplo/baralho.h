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
    Baralho() {
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 9; j++) {
                baralho.push_back({"Azul,", std::to_string(j), "normal"});
            }
        }
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 9; j++) {
                baralho.push_back({"Amarela,", std::to_string(j), "normal"});
            }
        }
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 9; j++) {
                baralho.push_back({"Verde,", std::to_string(j), "normal"});
            }
        }
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 9; j++) {
                baralho.push_back({"Vermelha,", std::to_string(j), "normal"});
            }
        }
        for (int i = 0; i <= 1; i++) {
            baralho.push_back({"Azul,", "+2", "normal"});
            baralho.push_back({"Azul,", "Bloqueia", "normal"});
            baralho.push_back({"Azul,", "Volta", "normal"});
        }
        for (int i = 0; i <= 1; i++) {
            baralho.push_back({"Amarela,", "+2", "normal"});
            baralho.push_back({"Amarela,", "Bloqueia", "normal"});
            baralho.push_back({"Amarela,", "Volta", "normal"});
        }
        for (int i = 0; i <= 1; i++) {
            baralho.push_back({"Verde,", "+2", "normal"});
            baralho.push_back({"Verde,", "Bloqueia", "normal"});
            baralho.push_back({"Verde,", "Volta", "normal"});
        }
        for (int i = 0; i <= 1; i++) {
            baralho.push_back({"Vermelha,", "+2", "normal"});
            baralho.push_back({"Vermelha,", "Bloqueia", "normal"});
            baralho.push_back({"Vermelha,", "Volta", "normal"});
        }
        for (int i = 0; i <= 3; i++) {
            baralho.push_back({"Preta,", "Compra +4", "especial"});
        }
        for (int i = 0; i <= 3; i++) {
            baralho.push_back({"Preta,", "Muda Cor", "especial"});
        }
    }
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
    BaralhoJogador(Baralho &b) {
        for (int i = 0; i <= 7; i++) {
            long unsigned int rand = random(0, b.get_size());
            int abbreviated_rand = rand & INT_MAX;
            Carta t = b.get_c(rand);
            baralhoJogador.push_back(t);
            b.eraseC(abbreviated_rand);
        }
    }
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
    PilhaJogo(Baralho &b) {
        long unsigned int rand = random(0, b.get_size() - 1);
        int abbreviated_rand = rand & INT_MAX;
        Carta t = b.get_c(rand);
        pilhaJogo.push_back(t);
        b.eraseC(abbreviated_rand);
    }
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
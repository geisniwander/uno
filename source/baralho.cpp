#include "exemplo/baralho.h"

#include <algorithm>
#include <climits>
#include <memory>
#include <random>
#include <vector>

#include "exemplo/carta.h"

namespace trabalho {
std::random_device rd;
std::mt19937 gen(rd());

BaralhoJogador::BaralhoJogador(Baralho& b) {
    for (int i = 0; i <= 7; i++) {
        long unsigned int rand = random(0, b.get_size());
        int abbreviated_rand = rand & INT_MAX;
        Carta t = b.get_c(rand);
        baralhoJogador.push_back(t);
        b.eraseC(abbreviated_rand);
    }
}

Baralho::Baralho() {
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

PilhaJogo::PilhaJogo(Baralho& b) {
    long unsigned int rand = random(0, b.get_size() - 1);
    int abbreviated_rand = rand & INT_MAX;
    Carta t = b.get_c(rand);
    pilhaJogo.push_back(t);
    b.eraseC(abbreviated_rand);
}

void PilhaJogo::muda_cor(int cor) {
    if (cor == 1)
        pilhaJogo.push_back(Carta("Amarela,", "20", "normal"));
    else if (cor == 2)
        pilhaJogo.push_back(Carta("Azul,", "20", "normal"));
    else if (cor == 3)
        pilhaJogo.push_back(Carta("Verde,", "20", "normal"));
    else if (cor == 4)
        pilhaJogo.push_back(Carta("Vermelha,", "20", "normal"));
}
/*---------------POLIMORFISMO---------------*/
Carta Baralho::get_c(long unsigned int i) {
    return baralho.at(i);
}
Carta BaralhoJogador::get_c(long unsigned int i) {
    return baralhoJogador.at(i);
}
Carta PilhaJogo::get_c(long unsigned int i) {
    return pilhaJogo.at(i);
}
/*---------------POLIMORFISMO---------------*/

long unsigned int Baralho::get_size() {
    long unsigned int size = baralho.size();
    return size;
}
long unsigned int PilhaJogo::get_size() {
    long unsigned int size = pilhaJogo.size();
    return size;
}
long unsigned int BaralhoJogador::get_size() {
    unsigned long int size = baralhoJogador.size() - 1;
    return size;
}
long unsigned int Baralho::random(long unsigned int low, long unsigned int high) {
    std::uniform_int_distribution<long unsigned int> dist(low, high);
    return dist(gen);
}
void Baralho::eraseC(int i) {
    baralho.erase(baralho.begin() + i);
}
void BaralhoJogador::eraseCj(long unsigned int i) {
    int abbreviated_i = i & INT_MAX;
    baralhoJogador.erase(baralhoJogador.begin() + abbreviated_i);
}
void PilhaJogo::adicionaCarta(Carta& a) {
    pilhaJogo.push_back(a);
}
void BaralhoJogador::comprar(Baralho& b, long unsigned int qtd) {
    if (b.get_size() <= qtd) {
        return;
    } else {
        for (long unsigned int i = 0; i < qtd; i++) {
            long unsigned int rand = random(0, b.get_size() - 1);
            int abbreviated_rand = rand & INT_MAX;
            Carta comprada = b.get_c(rand);
            baralhoJogador.push_back(comprada);
            b.eraseC(abbreviated_rand);
        }
    }
}

bool BaralhoJogador::verificaVitoria() {
    if ((baralhoJogador.size() - 1) == 0)
        return true;
    else
        return false;
}

}  // namespace trabalho

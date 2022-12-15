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

#include "baralho.h"

#include <algorithm>
#include <climits>
#include <memory>
#include <random>
#include <vector>

#include "carta.h"
#include "ponteiros.cpp"

namespace trabalho {
std::random_device rd;
std::mt19937 gen(rd());

/*-------------POLIMORFISMO------------------*/
Carta Baralho::get_c(long unsigned int i) {
    return baralho.at(i);
}
Carta BaralhoJogador::get_c(long unsigned int i) {
    return baralhoJogador.at(i);
}
Carta PilhaJogo::get_c(long unsigned int i) {
    return pilhaJogo.at(i);
}
/*-------------POLIMORFISMO------------------*/

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
void BaralhoJogador::comprar(Baralho& b) {
    if (b.get_size() <= 1) {
        return;
    } else {
        long unsigned int rand = random(0, b.get_size() - 1);
        int abbreviated_rand = rand & INT_MAX;
        Carta comprada = b.get_c(rand);
        baralhoJogador.push_back(comprada);
        b.eraseC(abbreviated_rand);
    }
}
}  // namespace trabalho


#include <exemplo/baralho.h>
#include <exemplo/carta.h>
#include <exemplo/jogo.h>

#include <../source/baralho.cpp>
#include <../source/carta.cpp>
#include <../source/jogo.cpp>
#include <iostream>
#include <string>

int main() {
    using namespace trabalho;
    Jogo novoJogo;
    novoJogo.jogar();
    return 0;
}
#include "carta.h"

#include <iostream>
#include <string>

namespace trabalho {

std::string Carta::get_cor() {
    return cor;
}

std::string Carta::get_valor() {
    return valor;
}

std::string Carta::get_tipo() {
    return tipo;
}

void Carta::set_cor(std::string a) {
    cor = a;
}

void Carta::set_valor(std::string a) {
    valor = a;
}

void Carta::set_tipo(std::string a) {
    tipo = a;
}

}  // namespace trabalho

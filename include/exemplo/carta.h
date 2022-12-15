#include <iostream>
#include <string>
#ifndef CARTA_H
#define CARTA_H

namespace trabalho {

/*-------CLASSES, MÉTODOS, ATRIBUTOS, CONTRUTORES E DESTRUIDORES----------*/
class Carta {
   private:
    std::string cor = "";
    std::string valor = "";
    std::string tipo = "";

   public:
    Carta(std::string a, std::string b, std::string c);
    ~Carta() = default;
    std::string get_cor();
    std::string get_valor();
    std::string get_tipo();
    void set_cor(std::string a);
    void set_valor(std::string a);
    void set_tipo(std::string a);
    bool compara(Carta &pilha);
};

/*-------SOBRECARGA DE OPERADOR----------*/
std::ostream &operator<<(std::ostream &saida, Carta &c) {
    saida << "Cor: " << c.get_cor() << " Valor: " << c.get_valor() << std::endl;
    return saida;
}
/*-------SOBRECARGA DE OPERADOR----------*/

}  // namespace trabalho
#endif
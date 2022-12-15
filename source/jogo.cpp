#include "exemplo/jogo.h"

#include <iostream>
#include <string>

namespace trabalho {

void Jogo::jogar() {
    std::string iniciar = "S";
    std::string terminar = "N";
    std::string msgInvalida = "CARTA INVÁLIDA! Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
    std::string msgMudaCor = "Escolha o número da cor para mudar:\n [1] Amarela,\n [2] Azul,\n [3] Verde,\n [4] Vermelha ";
    std::string msgJogue = "Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
    std::string msgQuebraLinha = "---------------------------";

    while (b1->get_size() > 4) {
        while (iniciar == "S") {
            while (terminar != "S") {
                int j1_fim = 0;
                int j2_fim = 1;
                while (j1_fim == 0) {
                    std::cout << *bj;
                    std::cout << *pj;
                    long unsigned int escolhida = 100;
                    std::cout << msgJogue;
                    std::cin >> escolhida;
                    while (escolhida > (bj->get_size() - 1) && escolhida != 100) {
                        std::cout << msgInvalida;
                        std::cin >> escolhida;
                    }
                    while (escolhida == 100) {
                        bj->comprar(*b1, 1);
                        std::cout << *bj;
                        std::cout << *pj;
                        std::cout << msgJogue;
                        std::cin >> escolhida;
                        while (escolhida > (bj->get_size() - 1) && escolhida != 100) {
                            std::cout << msgInvalida;
                            std::cin >> escolhida;
                        }
                    }
                    Carta pilha = pj->get_c(pj->get_size() - 1);
                    Carta escolha = bj->get_c(escolhida);
                    if (escolha.compara(pilha)) {
                        std::cout << ("Muito Bem!") << std::endl;
                        pj->adicionaCarta(escolha);
                        bj->eraseCj(escolhida);
                        if (escolha.get_valor() == "+2") {
                            bj2->comprar(*b1, 2);
                        }
                        if (escolha.get_valor() == "Compra +4") {
                            bj2->comprar(*b1, 4);
                        }
                        if (escolha.get_valor() == "Muda Cor") {
                            int cor = 10;
                            while (cor <= 0 || cor >= 5) {
                                std::cout << msgQuebraLinha << std::endl;
                                std::cout << msgMudaCor << std::endl;
                                std::cin >> cor;
                            }
                            pj->muda_cor(cor);
                        }
                        j1_fim = 1;
                        j2_fim = 0;
                        if (escolha.get_valor() == "Bloqueia") {
                            j1_fim = 0;
                            j2_fim = 1;
                        }
                    }
                    if (bj->verificaVitoria()) {
                        std::cout << "JOGADOR 1 GANHOU!" << std::endl;
                        terminar = "S";
                        j1_fim = 1;
                        j2_fim = 1;
                        return;
                    }
                }

                while (j2_fim == 0) {
                    std::cout << *bj2;
                    std::cout << *pj;
                    long unsigned int escolhida = 100;
                    std::cout << msgJogue;
                    std::cin >> escolhida;
                    while (escolhida > (bj2->get_size() - 1) && escolhida != 100) {
                        std::cout << msgInvalida;
                        std::cin >> escolhida;
                    }
                    while (escolhida == 100) {
                        if (b1->get_size() <= 1) {
                        } else {
                            bj2->comprar(*b1, 1);
                            std::cout << *bj2;
                            std::cout << *pj;
                            std::cout << msgJogue;
                            std::cin >> escolhida;
                            while (escolhida > (bj2->get_size() - 1) && escolhida != 100) {
                                std::cout << msgInvalida;
                                std::cin >> escolhida;
                            }
                        }
                    }
                    Carta pilha = pj->get_c(pj->get_size() - 1);
                    Carta escolha = bj2->get_c(escolhida);
                    if (escolha.compara(pilha)) {
                        std::cout << ("Muito Bem!") << std::endl;
                        pj->adicionaCarta(escolha);
                        bj2->eraseCj(escolhida);
                        if (escolha.get_valor() == "+2") {
                            bj->comprar(*b1, 2);
                        }
                        if (escolha.get_valor() == "Compra +4") {
                            bj->comprar(*b1, 4);
                        }
                        if (escolha.get_valor() == "Muda Cor") {
                            int cor = 10;
                            while (cor <= 0 || cor >= 5) {
                                std::cout << msgQuebraLinha << std::endl;
                                std::cout << msgMudaCor << std::endl;
                                std::cin >> cor;
                            }
                            pj->muda_cor(cor);
                        }
                        j1_fim = 0;
                        j2_fim = 1;
                        if (escolha.get_valor() == "Bloqueia") {
                            j1_fim = 1;
                            j2_fim = 0;
                        }
                    }
                    if (bj2->verificaVitoria()) {
                        std::cout << "JOGADOR 2 GANHOU!" << std::endl;
                        terminar = "S";
                        j1_fim = 1;
                        j2_fim = 1;
                        return;
                    }
                }
            }
        }
    }
}
}  // namespace trabalho
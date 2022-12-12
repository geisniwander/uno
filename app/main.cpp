#include <exemplo/baralho.h>
#include <exemplo/carta.h>

#include <exemplo/baralho.cpp>
#include <exemplo/carta.cpp>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace trabalho;
    std::string iniciar = "N";
    std::string terminar = "N";
    /*-------------OBJETOS------------------*/
    Baralho b1;
    BaralhoJogador bj(b1);
    BaralhoJogador bj2(b1);
    PilhaJogo pj(b1);
    /*-------------OBJETOS------------------*/

    while (iniciar != "S") {
        std::cout << "Iniciar o jogo? (S/N)";
        std::cin >> iniciar;
    }
    while (b1.get_size() > 4) {
        while (iniciar == "S") {
            while (terminar != "S") {
                int j1_fim = 0;
                int j2_fim = 1;
                while (j1_fim == 0) {
                    std::cout << "Jogador 1 joga:" << std::endl;
                    std::cout << "Cartas Jogador 1:" << std::endl;
                    std::cout << bj;
                    std::cout << "-------------" << std::endl;
                    std::cout << "Carta da pilha: " << std::endl;
                    std::cout << pj;
                    std::cout << "-------------" << std::endl;
                    long unsigned int escolhida = 100;
                    std::cout << "Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                    std::cin >> escolhida;
                    while (escolhida > (bj.get_size() - 1) && escolhida != 100) {
                        std::cout << "CARTA INVÁLIDA! Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                        std::cin >> escolhida;
                    }
                    while (escolhida == 100) {
                        if (b1.get_size() <= 1) {
                            return 0;
                        } else {
                            bj.comprar(b1);
                        }
                        std::cout << "Jogador 1 joga:" << std::endl;
                        std::cout << "Cartas Jogador 1:" << std::endl;
                        std::cout << bj;
                        std::cout << "-------------" << std::endl;
                        std::cout << "Carta da pilha: " << std::endl;
                        std::cout << pj;
                        std::cout << "-------------" << std::endl;
                        std::cout << "Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                        std::cin >> escolhida;
                        while (escolhida > (bj.get_size() - 1) && escolhida != 100) {
                            std::cout << "CARTA INVÁLIDA! Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                            std::cin >> escolhida;
                        }
                    }
                    Carta pilha = pj.get_c(pj.get_size() - 1);
                    Carta escolha = bj.get_c(escolhida);
                    if (((pilha.get_cor() == escolha.get_cor()) || (pilha.get_valor() == escolha.get_valor()) || escolha.get_tipo() == "especial" || (escolha.get_tipo() != pilha.get_tipo()))) {
                        std::cout << ("Muito Bem!") << std::endl;
                        pj.adicionaCarta(escolha);
                        bj.eraseCj(escolhida);
                        if (escolha.get_valor() == "+2") {
                            if (b1.get_size() - 2 <= 1) {
                                return 0;

                            } else {
                                bj2.comprar(b1);
                                bj2.comprar(b1);
                            }
                        }
                        if (escolha.get_valor() == "Compra +4") {
                            for (int i = 0; i <= 3; i++) {
                                if (b1.get_size() <= 1) {
                                    return 0;

                                } else {
                                    bj2.comprar(b1);
                                }
                            }
                        }
                        if (escolha.get_valor() == "Muda Cor") {
                            int cor = 10;
                            while (cor != 1 && cor != 2 && cor != 3 && cor != 4) {
                                std::cout << "-------------" << std::endl;
                                std::cout << "Escolha o número da cor para mudar:\n [1] Amarela,\n [2] Azul,\n [3] Verde,\n [4] Vermelha" << std::endl;
                                std::cin >> cor;
                            }
                            if (cor == 1) {
                                Carta novaCor("Amarela,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 2) {
                                Carta novaCor("Azul,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 3) {
                                Carta novaCor("Verde,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 4) {
                                Carta novaCor("Vermelha,", "20", "normal");
                                pj.adicionaCarta(novaCor);
                            }
                        }
                        j1_fim = 1;
                        j2_fim = 0;
                        if (escolha.get_valor() == "Bloqueia") {
                            j1_fim = 0;
                            j2_fim = 1;
                        }
                    }
                    if (bj.get_size() == 0) {
                        std::cout << "JOGADOR 1 GANHOU!" << std::endl;
                        terminar = "S";
                        j1_fim = 1;
                        j2_fim = 1;
                    }
                }

                while (j2_fim == 0) {
                    std::cout << "Jogador 2 joga:" << std::endl;
                    std::cout << "Cartas Jogador 2:" << std::endl;
                    std::cout << bj2;
                    std::cout << "-------------" << std::endl;
                    std::cout << "Carta da pilha: " << std::endl;
                    std::cout << pj;
                    std::cout << "-------------" << std::endl;
                    long unsigned int escolhida = 100;
                    std::cout << "Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                    std::cin >> escolhida;
                    while (escolhida > (bj2.get_size() - 1) && escolhida != 100) {
                        std::cout << "CARTA INVÁLIDA! Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                        std::cin >> escolhida;
                    }
                    while (escolhida == 100) {
                        if (b1.get_size() <= 1) {
                            return 0;
                        } else {
                            bj2.comprar(b1);
                            std::cout << "Jogador 2 joga:" << std::endl;
                            std::cout << "Cartas Jogador 2:" << std::endl;
                            std::cout << bj2;
                            std::cout << "-------------" << std::endl;
                            std::cout << "Carta da pilha: " << std::endl;
                            std::cout << pj;
                            std::cout << "-------------" << std::endl;
                            std::cout << "Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                            std::cin >> escolhida;
                            while (escolhida > (bj2.get_size() - 1) && escolhida != 100) {
                                std::cout << "CARTA INVÁLIDA! Digite o número da carta que deseja jogar, ou 100 para comprar uma nova carta: ";
                                std::cin >> escolhida;
                            }
                        }
                    }
                    Carta pilha = pj.get_c(pj.get_size() - 1);
                    Carta escolha = bj2.get_c(escolhida);
                    if (((pilha.get_cor() == escolha.get_cor()) || (pilha.get_valor() == escolha.get_valor()) || escolha.get_tipo() == "especial" || (escolha.get_tipo() != pilha.get_tipo()))) {
                        std::cout << ("Muito Bem!") << std::endl;
                        pj.adicionaCarta(escolha);
                        bj2.eraseCj(escolhida);
                        if (escolha.get_valor() == "+2") {
                            if (b1.get_size() - 2 <= 0) {
                                return 0;

                            } else {
                                bj.comprar(b1);
                                bj.comprar(b1);
                            }
                        }
                        if (escolha.get_valor() == "Compra +4") {
                            for (int i = 0; i <= 3; i++) {
                                if (b1.get_size() - 4 <= 1) {
                                    std::cout << "-------------" << std::endl;
                                    std::cout << "AS CARTAS ACABARAM. FIM DE JOGO!" << std::endl;
                                } else {
                                    bj.comprar(b1);
                                }
                            }
                        }
                        if (escolha.get_valor() == "Muda Cor") {
                            int cor = 10;
                            while (cor != 1 && cor != 2 && cor != 3 && cor != 4) {
                                std::cout << "-------------" << std::endl;
                                std::cout << "Escolha o número da cor para mudar:\n [1] Amarela,\n [2] Azul,\n [3] Verde,\n [4] Vermelha" << std::endl;
                                std::cin >> cor;
                            }
                            if (cor == 1) {
                                Carta novaCor("Amarela,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 2) {
                                Carta novaCor("Azul,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 3) {
                                Carta novaCor("Verde,", "20", "normal");
                                pj.adicionaCarta(novaCor);

                            } else if (cor == 4) {
                                Carta novaCor("Vermelha,", "20", "normal");
                                pj.adicionaCarta(novaCor);
                            }
                        }
                        j1_fim = 0;
                        j2_fim = 1;
                        if (escolha.get_valor() == "Bloqueia") {
                            j1_fim = 1;
                            j2_fim = 0;
                        }
                    }
                    if (bj2.get_size() == 0) {
                        std::cout << "JOGADOR 2 GANHOU!" << std::endl;
                        terminar = "S";
                        j1_fim = 1;
                        j2_fim = 1;
                    }
                }
            }
        }
    }
    b1.~Baralho();
    bj.~BaralhoJogador();
    bj2.~BaralhoJogador();
    pj.~PilhaJogo();
    return 0;
}
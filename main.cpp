#include <iostream>
#include <list>
#include <string.h>

#include "cliente.h"
#include "filme.h"
#include "locacao.h"
#include "util.cpp"
#include "menus.cpp"
#include "filme_controller.cpp"
#include "cliente_controller.cpp"
#include "locacao_controller.cpp"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void preencherListasTestes() {
    filmes.push_front(makeFilmeTeste());
    filmes.push_front(makeFilmeTeste());

    clientes.push_front(makeClienteTeste());
    clientes.push_front(makeClienteTeste());

    locacoes.push_front(makeLocacaoTeste(0));
    locacoes.push_front(makeLocacaoTeste(1));

}

int main() {
    // output em unicode
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    preencherListasTestes();

    while (true) {
        clear_screen();
        switch (menu()) {
            case 1:
                switch (menuAcervo()) {
                    case 1:
                        listarAcervo();
                        enterToContinue();
                        break;

                    case 2:
                        cadastrarFilme();
                        enterToContinue();
                        break;

                    case 3:
                        alterarFilme();
                        enterToContinue();
                        break;

                    case 4:
                        excluirFilme();
                        enterToContinue();
                        break;
                        

                    default:
                        break;
                }
                break;

            case 2:
                switch (menuCliente()) {
                    case 1:
                        listarCliente();
                        enterToContinue();
                        break;

                    case 2:
                        cadastrarCliente();
                        enterToContinue();
                        break;

                    case 3:
                        alterarCliente();
                        enterToContinue();
                        break;

                    case 4:
                        excluirCliente();
                        enterToContinue();
                        break;

                    default:
                        break;
                }
                break;

            case 3:
                switch (menuLocacoes()) {
                    case 1:
                        listarLocacao();
                        enterToContinue();
                        break;
                    case 2:
                        locarFilme();
                        enterToContinue();
                        break;
                    case 3:
                        devolucaoFilme();
                        enterToContinue();
                        break;

                    case 4:
                        listarNaoLocados();
                        enterToContinue();
                        break;

                    case 5:
                        mostrarFaturamento();
                        enterToContinue();
                        break;

                    default:
                        break;
                }
                break;
            case 0:
                goto exit_loop;
            default:
                goto exit_loop;
        }
    }
    exit_loop:;
}
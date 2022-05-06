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

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

list<Locacao> locacoes;

Locacao makeLocacaoTeste(int position) {
    Locacao locacao{};
    locacao.id = getNextId();
    auto clientePosition = std::next(clientes.begin(), position);
    locacao.cliente = *clientePosition;
    auto filmePosition = std::next(filmes.begin(), position);
    locacao.filme = *filmePosition;

    return locacao;
}

void preencherListasTestes() {
    filmes.push_front(makeFilmeTeste());
    filmes.push_front(makeFilmeTeste());

    clientes.push_front(makeClienteTeste());
    clientes.push_front(makeClienteTeste());

    locacoes.push_front(makeLocacaoTeste(0));
    locacoes.push_front(makeLocacaoTeste(1));

}

void listarLocacao() {
    for (Locacao const &lc: locacoes) {
        printf(linhasDeCima);
        printf("|   Id: %d\n", lc.id);
        printf("|   Cliente:  %s\n", lc.cliente.nome);
        printf("|   Filme:  %s", lc.filme.titulo);
        printf(linhasDeBaixo);
    }
}

void locarFilme() {
    int idFilme;
    int idCliente;
    Locacao locacao{};

    listarAcervo();
    printf("Escolha um filme pelo ID: ");
    scanf("%d", &idFilme);
    locacao.filme = getFilmeById(idFilme);
    if (!locacao.filme.id) {
        printf("Filme inexistente! ");
        return;
    }

    listarCliente();
    printf("Escolha um cliente pelo ID: ");
    scanf("%d", &idCliente);
    locacao.cliente = getClienteById(idCliente);
    if (!locacao.cliente.id) {
        printf("Cliente inexistente! ");
        return;
    }

    locacao.id = getNextId();
    locacoes.push_back(locacao);
    printf("Filme locado! \n");
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

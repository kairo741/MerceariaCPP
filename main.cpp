#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include "cliente.h"
#include "filme.h"
#include "locacao.h"
using namespace std;

#define linhasDeCima "\n╭──────────────────────────╮\n"
#define linhasDeBaixo "\n╰──────────────────────────╯\n"

int idCounter = 0;

list<Filme> filmes;
list<Cliente> clientes;
list<Locacao> locacoes;

int getNextId()
{
    idCounter += 1;
    return idCounter;
}


Cliente makeClienteTeste()
{
    Cliente cli;
    cli.id = getNextId();
    strcpy(cli.nome, "Cliente");
    strcpy(cli.idade, "20");

    return cli;
}

Locacao makeLocacaoTeste(int position)
{
    Locacao locacao{};
    locacao.id = getNextId();
    auto clientePosition = std::next(clientes.begin(), position);
    locacao.cliente = *clientePosition;
    auto filmePosition = std::next(filmes.begin(), position);
    locacao.filme = *filmePosition;

    return locacao;
}

Filme makeFilmeTeste()
{
    Filme filme;
    filme.id = getNextId();
    strcpy(filme.titulo, "Kairo O Filme");
    strcpy(filme.genero, "Kairo Amorim");
    filme.valorLocacao = 15;

    return filme;
}

void preencherListasTestes()
{
    filmes.push_front(makeFilmeTeste());
    filmes.push_front(makeFilmeTeste());

    clientes.push_front(makeClienteTeste());
    clientes.push_front(makeClienteTeste());

    locacoes.push_front(makeLocacaoTeste(0));
    locacoes.push_front(makeLocacaoTeste(1));

}

int menu()
{
    int opcao;

    printf("\n===Menu===\n\n1. Acervo\n2. Clientes\n3. Filmes locados\n0. Sair\n\nDigite uma opção: \t");

    std::cin >> opcao;

    return opcao;
}

int menuAcervo()
{
    int opcao;

    printf("\n===Acervo===\n\n1. Listar Filmes\n2. Cadastrar Filmes\n3. Editar Filmes\n4. Excluir Filmes\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> opcao;

    return opcao;
}

int menuCliente()
{
    int opcao;

    printf("\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: ");

    scanf("%d", &opcao);

    return opcao;
}

int menuLocacoes()
{
    int opcao;
    printf("\n===Locações===\n\n1.Locar um filme \n2.Deslocar um filme \n3. Listar Locados\n4.Listar Não Locados\n0. Voltar\n\nDigite uma opção: ");

    scanf("%d", &opcao);

    return opcao;

}

void cadastrarFilme()
{
    Filme filme;

    filme.id = getNextId();

    printf("Digite o nome do filme: ");
    scanf("%s", filme.titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", filme.genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filme.valorLocacao);

    filmes.push_front(filme);
}

void cadastrarCliente(){

    Cliente cli;

    cli.id = getNextId();

    printf("Digite o nome do cliente: ");
    scanf("%s", cli.nome);
    printf("Digite a idade do cliente: ");
    scanf("%s", cli.idade);

    clientes.push_front(cli);
}

void listarLocacao()
{
    for (Locacao const &lc : locacoes)
    {
        printf(linhasDeCima);
        printf("|   Id: %d\n", lc.id);
        printf("|   Cliente:  %s\n", lc.cliente.nome);
        printf("|   Filme:  %s", lc.filme.titulo);
        printf(linhasDeBaixo);
    }
}

void listarAcervo()
{
    for (Filme const &fm : filmes)
    {
        printf(linhasDeCima);
        printf("   Id: %d\n", fm.id);
        printf("   Titulo:  %s\n", fm.titulo);
        printf("   Gênero:  %s\n", fm.genero);
        printf("   Valor da Locação: R$%d", fm.valorLocacao);
        printf(linhasDeBaixo);
    }
}

void listarCliente()
{
    for (Cliente const &cli : clientes)
    {
        printf(linhasDeCima);
        printf("   Id: %d\n", cli.id);
        printf("   Nome: %s\n", cli.nome);
        printf("   Idade: %s", cli.idade);
        printf(linhasDeBaixo);
    }
}

int main()
{
    // output em unicode
    SetConsoleOutputCP(65001);
    preencherListasTestes();

    while (true)
    {
        switch (menu()) {
            case 1:
                switch (menuAcervo())
                {
                    case 1:
                        listarAcervo();
                        break;

                    case 2:
                        cadastrarFilme();
                        break;

                    default:
                        break;
                }
                break;
            case 2:
                switch (menuCliente())
                {
                    case 1:
                        listarCliente();
                        break;

                    case 2:
                        cadastrarCliente();
                        break;

                    default:
                        break;
                }
                break;
            case 3:
                listarLocacao();
                break;
            case 0:
                goto exit_loop;
            default:
                goto exit_loop;
                break;
        }
    }
    exit_loop: ;
}

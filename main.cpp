#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include "cliente.h"
#include "filme.h"
using namespace std;

#define linhasDeCima "\n╭──────────────────────────╮\n"
#define linhasDeBaixo "\n╰──────────────────────────╯\n"

int idCounter = 0;

list<Filme> filmes;
list<Cliente> clientes;

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
}

int menu()
{
    int opcao;

    printf("\n===Menu===\n\n1. Acervo\n2. Clientes\n0. Sair\n\nDigite uma opção: ");

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

void cadastrarFilme()
{
    Filme filme;

    filme.id = getNextId();

    printf("Digite o nome do filme: ");
    scanf("%s", &filme.titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", &filme.genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filme.valorLocacao);

    filmes.push_front(filme);
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

    int opcao = 1;
    preencherListasTestes();

    while (true)
    {
        opcao = menu();

        if (opcao == 1)
        {
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
        }

        else if (opcao == 2)
        {
            switch (menuCliente())
            {
            case 1:
                listarCliente();
                break;

            case 2:
                break;

            default:
                break;
            }
        }
        else if (opcao == 0)
        {
            break;
        }
    }
}

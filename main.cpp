#include <iostream>
#include <list>
#include "cliente.h"
#include "filme.h"
#include "util.h"
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define linhasDeCima "╭──────────────────────────╮ "
#define linhasDeBaixo "╰──────────────────────────╯ "

void adicionarFilme();
void excluirFilme();

list<Filme> filmes;

int menu()
{
    int opcao;

    std::cout << "\n===Menu===\n\n1. Acervo\n2. Clientes\n0. Sair\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

int menuAcervo()
{
    int opcao;

    std::cout << "\n===Acervo===\n\n1. Listar Filmes\n2. Cadastrar Filmes\n3. Editar Filmes\n4. Excluir Filmes\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

void listarAcervo()
{
    for (Filme const &i : filmes)
    {
        string titulo = "   Titulo: ";
        string genero = "   Gênero: ";
        string valorLocacao = "   Valor da Locação: R$";

        std::cout << linhasDeCima << std::endl;
        std::cout << titulo + i.titulo << std::endl;
        std::cout << genero + i.genero << std::endl;
        std::cout << valorLocacao + to_string(i.valorLocacao)<< std::endl;
        std::cout << linhasDeBaixo << std::endl;
    }
}


void listarCliente()
{
    for (Cliente const &i : cliente)
    {
        string id = "   Id: "
        string nome = "   Nome: ";
        string idade = "   Idade: ";

        std::cout << linhasDeCima << std::endl;
        std::cout << id + to_string(i.id) << std::endl;
        std::cout << nome + i.nome << std::endl;
        std::cout << idade + to_string(i.idade) << std::endl;
        std::cout << linhasDeBaixo << std::endl;
    }
}

int menuCliente()
{
    int opcao;

    std::cout << "\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

void cadastrarFilme(){
    printf("Bobão cadstro\n");
    Filme filme;
    std::cout << "Digite o nome do filme: ";
    string tituloFilme = "";
    cin >> tituloFilme;
    std::cout << "Digite o genero do filme: ";
    string generoFilme = "";
    cin >> generoFilme;
    std::cout << "Digite o valor de locação do filme: ";
    int valorFilme = 0;
    cin >> valorFilme;
  
    strcpy(filme.titulo, tituloFilme.c_str());
    strcpy(filme.genero, generoFilme.c_str());
    filme.valorLocacao = valorFilme;

    std::cout << filme.titulo << std::endl;
    std::cout << filme.genero << std::endl;
    std::cout << filme.valorLocacao << std::endl;

    filmes.push_front(filme);
}


void preecherLista()
{
    Filme filme;
    strcpy(filme.titulo, "Kairo O Filme");
    strcpy(filme.genero, "Kairo Amorim");
    filme.valorLocacao = 15;

    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
}

int main()
{
    int opcao = 1;
    preecherLista();

    while (true)
    {
        opcao = menu();

        if (opcao == 1)
        {
            std::cout << "Size of the list<Filme>: " << int(filmes.size()) << '\n';
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
}

void adicionar()
{
    printf("\nDigite o titulo do filme: ");
    // scanf("%s", Filmes.titulo);
}

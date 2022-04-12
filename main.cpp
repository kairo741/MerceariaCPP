#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct Filme
{
    char nome[20];
    char autor[25];
    char estudio[30];
    int quantidade;
};

struct Cliente
{
    char nome[20];
    int idade[2];
    int numero[11];
    char a[1];
};

// void iniciar();

// void adicionarLivro();
// void excluirLivro();

list<Filme> filmes;

void adicionarFilme()
{
    Filme filme;
    printf("\nDigite o nome do livro: ");
    // scanf("%s", strcpy(filme.nome));
    cin.get(filme.nome, 50);
    std::cout << filme.nome << std::endl;
}

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

    std::cout << "\n===Acervo===\n\n1. Listar Livros\n2. Cadastrar Livros\n3. Editar Livros\n4. Excluir Livros\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    if (opcao == 2)
    {
        std::cout << "menuAcervo - op2" << std::endl;
        adicionarFilme();
    }

    return opcao;
}

int menuCliente()
{
    int opcao;

    std::cout << "\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

int main()
{

    int opcao = 1;

    Filme filme;
    strcpy(filme.nome, "Kairo O Filme");
    strcpy(filme.autor, "Kairo Amorim");
    strcpy(filme.estudio, "Kairos Studios");
    filme.quantidade = 15;

    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);
    filmes.push_front(filme);

    std::cout << "Size of the list<Filme>: " << int(filmes.size()) << '\n';

    while (true)
    {
        opcao = menu();

        if (opcao == 1)
        {
            menuAcervo();
        }

        else if (opcao == 2)
        {
            menuCliente();
        }

        else if (opcao == 0)
        {
            std::cout << "Saindo..." << std::endl;
            break;
        }
    }
}

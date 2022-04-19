#include <iostream>
#include <list>
#include "cliente.h"
#include "filme.h"
#include <string.h>
using namespace std;

void adicionarLivro();
void excluirLivro();

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

    std::cout << "\n===Acervo===\n\n1. Listar Livros\n2. Cadastrar Livros\n3. Editar Livros\n4. Excluir Livros\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

int menuCliente()
{
    int opcao;

    std::cout << "\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

void preecherLista(){
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
        
        struct livros;

        if (opcao == 1)
        {
            std::cout << "Size of the list<Filme>: " << int(filmes.size()) << '\n';
            menuAcervo();
            
            if (opcao == 2)
            {
            	// adicionar(livros);
            	// printf(livros.titulo);
            	
            }
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

void adicionar(){
	printf("\nDigite o titulo do filme: ");
	// scanf("%s", livros.titulo);
}




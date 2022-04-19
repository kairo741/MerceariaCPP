#include <iostream>
#include <list>
#include "cliente.h"
#include "filme.h"


void adicionarLivro();
void excluirLivro();

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

int main()
{
    int opcao = 1;
    
 
    
    while (true)
    {
        opcao = menu();
        
        struct livros;

        if (opcao == 1)
        {
            menuAcervo();
            
            if (opcao == 2)
            {
            	adicionar(livros);
            	printf(livros.nome);
            	
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
	printf("\nDigite o nome do livro: ");
	scanf("%s", livros.nome);
}




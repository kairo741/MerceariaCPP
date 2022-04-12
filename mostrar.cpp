#include <iostream>
#include <list>

using namespace std;

struct filmes
{
char nome[20];
char diretor[25];
char estudio[30];
int quantidade[3];

};

list<string> listaFilmes={"Rambo"};

void mostrarFilmes(){

    for(auto x:listaFilmes){
        cout << x << " ";
    };
};
int menu()
{
    int opcao;

    std::cout << "\n===Menu===\n\n1. Acervo\n2. Clientes\n0. Sair\n\nDigite uma opção: " << std::endl;

    std::cin >> opcao;

    return opcao;
}

int menuFilme()
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
            menuFilme();

            mostrarFilmes();
         
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






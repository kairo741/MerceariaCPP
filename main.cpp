#include <iostream>
#include <list>
#include <string.h>
#include "cliente.h"
#include "filme.h"
#include "locacao.h"
#include "util.cpp"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#define linhasDeCima "\n╭──────────────────────────╮\n"
#define linhasDeBaixo "\n╰──────────────────────────╯\n"


list<Filme> filmes;
list<Cliente> clientes;
list<Locacao> locacoes;


auto getPosFilmeById(int id){
    for(auto it = filmes.begin(); it != filmes.end(); it++){
        if(it -> id == id){
            return it;

        }
    }

}

auto getPosClienteById(int id){
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if(it -> id == id){
            return it;

        }
    }
}

Filme getFilmeById(int id) {
    for (Filme const &f: filmes) {
        if (f.id == id) {
            return f;
        }
    }
    return Filme();
}

Cliente getClienteById(int id) {
    for (Cliente const &cli: clientes) {
        if (cli.id == id) {
            return cli;
        }
    }
    return Cliente();
}

Cliente makeClienteTeste() {
    Cliente cli;
    cli.id = getNextId();
    strcpy(cli.nome, "Cliente");
    strcpy(cli.idade, "20");

    return cli;
}

Locacao makeLocacaoTeste(int position) {
    Locacao locacao{};
    locacao.id = getNextId();
    auto clientePosition = std::next(clientes.begin(), position);
    locacao.cliente = *clientePosition;
    auto filmePosition = std::next(filmes.begin(), position);
    locacao.filme = *filmePosition;

    return locacao;
}

Filme makeFilmeTeste() {
    Filme filme;
    filme.id = getNextId();
    strcpy(filme.titulo, "Kairo O Filme");
    strcpy(filme.genero, "Kairo Amorim");
    filme.valorLocacao = 15;

    return filme;
}

void preencherListasTestes() {
    filmes.push_front(makeFilmeTeste());
    filmes.push_front(makeFilmeTeste());

    clientes.push_front(makeClienteTeste());
    clientes.push_front(makeClienteTeste());

    locacoes.push_front(makeLocacaoTeste(0));
    locacoes.push_front(makeLocacaoTeste(1));

}


int menu() {
    int opcao;

    printf("\n===Menu===\n\n1. Acervo\n2. Clientes\n3. Locação\n0. Sair\n\nDigite uma opção: \t");

    std::cin >> opcao;
    clear_screen();
    return opcao;
}

int menuAcervo() {
    int opcao;

    printf("\n===Acervo===\n\n1. Listar Filmes\n2. Cadastrar Filmes\n3. Editar Filmes\n4. Excluir Filmes\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> opcao;

    return opcao;
}

int menuCliente() {
    int opcao;

    printf("\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: ");

    scanf("%d", &opcao);

    return opcao;
}

int menuLocacoes() {
    int opcao;
    printf("\n===Locações===\n\n1. Listar Locados \n2. Locar um filme \n3. Deslocar um filme\n4. Listar Não Locados\n0. Voltar\n\nDigite uma opção: ");

    scanf("%d", &opcao);

    return opcao;

}

void cadastrarFilme() {
    Filme filme{};

    filme.id = getNextId();

    printf("Digite o nome do filme: ");
    scanf("%s", filme.titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", filme.genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filme.valorLocacao);

    filmes.push_front(filme);
}

void cadastrarCliente() {

    Cliente cli{};

    cli.id = getNextId();

    printf("Digite o nome do cliente: ");
    scanf("%s", cli.nome);
    printf("Digite a idade do cliente: ");
    scanf("%s", cli.idade);

    clientes.push_front(cli);
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

void listarAcervo() {
    for (Filme const &fm: filmes) {
        printf(linhasDeCima);
        printf("   Id: %d\n", fm.id);
        printf("   Titulo:  %s\n", fm.titulo);
        printf("   Gênero:  %s\n", fm.genero);
        printf("   Valor da Locação: R$%d", fm.valorLocacao);
        printf(linhasDeBaixo);
    }
}

void listarCliente() {
    for (Cliente const &cli: clientes) {
        printf(linhasDeCima);
        printf("   Id: %d\n", cli.id);
        printf("   Nome: %s\n", cli.nome);
        printf("   Idade: %s", cli.idade);
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

void excluirCliente() {
    listarCliente();

    int id;

    printf("Digite o ID do cliente para excluir: ");
    scanf("%d", &id);

    clientes.remove(getClienteById(id));
}

void alterarFilme() {

    listarAcervo();

    int escolha;

    printf("Escolha o filme que sera modificado pelo numero dele: ex: 1, 2, 3...");
    scanf("%d", &escolha);

    auto filmeIterator = getPosFilmeById(escolha);

    printf("Digite o nome do filme: ");
    scanf("%s", &filmeIterator->titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", &filmeIterator->genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filmeIterator->valorLocacao);

}

void alterarCliente(){
    listarCliente();

    int escolha;

    printf("Escolha qual cliente sera modificado pelo numero dele: ex 1, 2, 3...");
    scanf("%d", &escolha);

    auto clienteIterator = getPosClienteById(escolha);

    printf("Digite o nome do Cliente: ");
    scanf("%s", &clienteIterator->nome);
    printf("Digite a idade do Cliente: ");
    scanf("%s", &clienteIterator->idade);

}

void excluirFilme() {
    listarAcervo();

    int id;

    printf("Digite o ID do filme para excluir: ");
    scanf("%d", &id);

    filmes.remove(getFilmeById(id));
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

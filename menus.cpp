#include <iostream>
#include "Util.h"

int menu() {
    int opcao;

    printf("\n===Menu===\n\n1. Acervo\n2. Clientes\n3. Locação\n0. Sair\n\nDigite uma opção: \t");

    std::cin >> opcao;
    Util::clearTerminal();
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
    printf("\n===Locações===\n\n1. Listar Locados \n2. Locar um filme \n3. Devolução de um filme\n4. Listar Não Locados\n5. Mostrar Faturamento\n0. Voltar\n\nDigite uma opção: ");

    scanf("%d", &opcao);

    return opcao;

}
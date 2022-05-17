#include<stdio.h>
#include"Util.cpp"
#include"cliente.h"
#include <list>

using namespace std;

#ifndef _arquivo_cliente_controller_cpp_
#define _arquivo_cliente_controller_cpp_

list<Cliente> clientes;

auto getPosClienteById(int id){
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if(it -> id == id){
            return it;

        }
    }
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

void cadastrarCliente() {

    Cliente cli{};

    cli.id = getNextId();

    printf("Digite o nome do cliente: ");
    scanf("%s", cli.nome);
    printf("Digite a idade do cliente: ");
    scanf("%s", cli.idade);

    clientes.push_front(cli);
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

void excluirCliente() {
    listarCliente();

    int id;

    printf("Digite o ID do cliente para excluir: ");
    scanf("%d", &id);

    clientes.remove(getClienteById(id));
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

#endif

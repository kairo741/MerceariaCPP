#include "CustomerController.h"
#include "Util.h"
#include <iostream>


CustomerController::CustomerController(CustomerRepository _customerRepository) {
    customerRepository = _customerRepository;
};

int CustomerController::menu()
{
    int option;

    printf("\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> option;

    

    return option;
}

Customer makeCustomer(){

    char name[50];
    double totalSpent=0;

    printf("\nNome do Cliente: ");
    scanf("%s",&name);

    printf("\nTotal Gasto do Cliente: ");
    scanf("%lf",&totalSpent);

    return Customer(0,name,totalSpent);
}

void CustomerController::list(){
    customerRepository.read();
}

void CustomerController::create(){
    Customer c = makeCustomer();

    c.setId(Util::getNextId());

    customerRepository.write(c);

}

void CustomerController::update(){
    int id;

    list();
    printf("\nPara alterar, selecione o ID do cliente: ");

    std::cin >> id;

    Customer c = makeCustomer();
    c.setId(customerRepository.getById(id).getId());
    customerRepository.replaceOrDelete(c);
}

void CustomerController::remove(){
    int id;

    list();
    printf("\nPara excluir, selecione o ID do cliente: ");


    std::cin >> id;
    customerRepository.replaceOrDelete(customerRepository.getById(id), true);
}

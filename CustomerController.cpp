#include "CustomerController.h"
#include "Util.h"
#include <iostream>


CustomerController::CustomerController(CustomerRepository _customerRepository) {
    customerRepository = _customerRepository;
};

int CustomerController::menu(){
    int option;

    printf("\n===Cliente===\n\n1. Listar Cliente\n2. Cadastrar Cliente\n3. Editar Cliente\n4. Excluir Cliente\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> option;

    return option;
}
void CustomerController::list(){
    customerRepository.read();
    Util::enterToContinue();
}
void CustomerController::create(){}
void CustomerController::update(){}
void CustomerController::remove(){}

// void mainCustomerMenu()
// {
//     // switch (menu())
//     // {
//     // case 1:
//     //     showCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 2:
//     //     registerCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 3:
//     //     updateCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 4:
//     //     deleteCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // default:
//     //     break;
//     // }
// }
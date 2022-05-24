#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <iostream>

#include "CustomerRepository.h"
#include "CustomerController.h"
#include "ProductRepository.h"
#include "ProductController.h"
#include "SaleController.h"


int mainMenu(){
    int opcao;

    printf("\n===Mercearia C++===\n\n1. Cliente\n2. Produto\n3. Venda\n0. Sair\n\nDigite uma opção: ");
    std::cin >> opcao;
    
    Util::clearTerminal();
    return opcao;
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    CustomerRepository customerRepository = CustomerRepository();
    ProductRepository productRepository = ProductRepository();
    
    CustomerController customerController = CustomerController(customerRepository);
    ProductController productController = ProductController(productRepository);
    SaleController saleController = SaleController(customerRepository, productRepository);

    while(true){
        Util::clearTerminal();

        switch(mainMenu()){
            case 1:
                switch (customerController.menu()){
                    case 1:
                        customerController.list();
                        break;
                    case 2:
                        customerController.create();
                        break;
                    case 3:
                        customerController.update();
                        break;
                    case 4:
                        customerController.remove();
                        break;
                    case 0:
                        break;
                }
                Util::enterToContinue();
                break;

            case 2:
                switch (productController.menu()){
                case 1:
                    productController.list();
                    break;
                case 2:
                    productController.create();
                    break;
                case 3:
                    productController.update();
                    break;
                case 4:
                    productController.remove();
                    break;
                case 0:
                    break;
                }
                Util::enterToContinue();
                break;

            case 3:
                switch (saleController.menu()){
                case 1:
                    saleController.makeSale();
                    break;
                case 2:
                    saleController.showTotalSpentPerCustomer();
                    break;
                case 0:
                    break;
                }
                Util::enterToContinue();
                break;

            case 0:
                goto while_exit;
                break;
        }
    }
    while_exit:;
    return 0;
}
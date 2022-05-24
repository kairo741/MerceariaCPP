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
    return opcao;
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    CustomerRepository cr = CustomerRepository();
    ProductRepository pr = ProductRepository();
    CustomerController cc = CustomerController(cr);
    ProductController pc = ProductController(pr);
    SaleController sc = SaleController(cr, pr);

    while(true){


        switch(mainMenu()){
            case 1:
                switch (cc.menu())
                {
                    case 1:
                        cc.list();
                        break;
                    case 2:
                        cc.create();
                        break;
                    case 3:
                        cc.update();
                        break;
                    case 4:
                        cc.remove();
                        break;
                    case 0:
                        break;
                }
                break;
            case 2:
                pc.menu();
                break;
            case 3:
                sc.menu();
                break;

            case 0:
                break;
        }

    }

    return 0;
}
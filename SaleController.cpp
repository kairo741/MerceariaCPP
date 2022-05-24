#include "SaleController.h"
#include "Util.h"
#include <stdio.h>
#include <iostream>

SaleController::SaleController(CustomerRepository _customerRepository, ProductRepository _productRepository){
    customerRepository = _customerRepository;
    productRepository = _productRepository;
}

int SaleController::menu()
{
    int opcao;

    printf("\n===Vendas===\n\n1. Realizar venda\n2. Visualizar Gastos Clientes\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> opcao;
    Util::clearTerminal();
    return opcao;
}

void SaleController::makeSale(){
    int customerId;
    int productId;
    int quantity;

    customerRepository.read();
    printf("Digite o ID de um cliente para realizar a venda: ");
    scanf("%d", &customerId);

    Customer c = customerRepository.getById(customerId);

    printf("Digite o ID do produto: ");
    scanf("%d", &productId);

    Product p = productRepository.getById(productId);

    printf("Informe a quantidade: ");
    scanf("%d", &quantity);

    if (quantity > p.getQuantity()){
        printf("\nQuantidade inválida");
        
    }
    else{
        p.setQuantity(p.getQuantity() - quantity);
        c.setTotalSpent(c.getTotalSpent()+(p.getPrice()*quantity));

        productRepository.replaceOrDelete(p);
        customerRepository.replaceOrDelete(c);
        printf("\nVenda realizada");
    }

    Util::enterToContinue();
}

void SaleController::showTotalSpentPerCustomer(){
    customerRepository.read();
    Util::enterToContinue();
}
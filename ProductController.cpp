#include "ProductController.h"
#include "Product.h"
#include "ProductRepository.h"
#include <iostream>

int ProductController::menu() {
    int opcao;

    printf("\n===Produto===\n\n1. Listar Produto\n2. Cadastrar Produto\n3. Editar Produto\n4. Excluir Produto\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> opcao;
    Util::clearTerminal();
    return opcao;
}

ProductController::ProductController(ProductRepository _productRepository) {
    productRepository = _productRepository;
}


void ProductController::list() {
    productRepository.read();
}

void ProductController::create() {
    //productRepository.write(this->newProduct());
}

void ProductController::update() {
    int id;

    list();
    printf("\n Para alterar, selecione o ID do cliente: ");

    std::cin >> id;

    Product p = makeProduct();
    p.setId(productRepository.getById(id).getId());
    productRepository.replaceOrDelete(p);
}

void ProductController::remove() {
    int id;

    list();
    printf("\nPara excluir, selecione o ID do produto: ");

    std::cin >> id;
    productRepository.replaceOrDelete(productRepository.getById(id), true);
}

Product makeProduct()
{

    char name[100];
    double price;
    int quantity;

    printf("\n Nome do Produto: ");
    scanf("%s", &name);

    printf("\n Nome do Produto: ");
    scanf("%lf", &price);

    printf("\n Nome do Produto: ");
    scanf("%d", &quantity);

    return Product(0, name, price, quantity);
}

// void mainProductMenu()
// {
//     // switch (menu())
//     // {
//     // case 1:
//     //     showProduct();
//     //     Util::enterToContinue();
//     //     break;

//     // case 2:
//     //     registerProduct();
//     //     Util::enterToContinue();
//     //     break;

//     // case 3:
//     //     updateProduct();
//     //     Util::enterToContinue();
//     //     break;

//     // case 4:
//     //     deleteProduct();
//     //     Util::enterToContinue();
//     //     break;

//     // default:
//     //     break;
//     // }
// }
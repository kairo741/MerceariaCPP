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
    productRepository.write(this->newProduct());
}

void ProductController::update() {
    // todo - receber o produto que será atualizado/substituido por parâmetro
    productRepository.replaceOrDelete(this->newProduct());
}

void ProductController::remove() {
    int id;

    list();
    printf("\nPara excluir, selecione o ID do produto: ");

    std::cin >> id;
    productRepository.replaceOrDelete(productRepository.getById(id), true);
}

Product ProductController::newProduct() {
    Product product{};

    product.setId(Util::getNextId());
    printf("Insira o nome do produto: ");

    char *productName = nullptr;
    scanf("%c", productName);
    product.setName(productName);

    printf("Insira o preço: ");
    double price = 0;
    scanf("%d", price);
    product.setPrice(price);

    printf("Insira a quantidade: ");
    int quantity = 0;
    scanf("%d", quantity);
    product.setQuantity(quantity);
    return product;
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
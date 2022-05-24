#include "ProductController.h"
#include "Product.h"
#include "ProductRepository.h"
#include <iostream>


int ProductController::menu() {
    int opcao;

    printf("\n===Produto===\n\n1. Listar Produto\n2. Cadastrar Produto\n3. Editar Produto\n4. Excluir Produto\n0. Voltar\n\nDigite uma opção: ");

    std::cin >> opcao;

    return opcao;
}

ProductController::ProductController(ProductRepository _productRepository) {
    productRepository = _productRepository;
}

Product makeProduct(){
    char name[100];
    double price;
    int quantity;

    printf("\nNome do Produto: ");
    scanf("%s", &name);

    printf("\nPreço do Produto: ");
    scanf("%lf", &price);

    printf("\nQuantidade do Produto: ");
    scanf("%d", &quantity);

    return Product(0, name, price, quantity);
}


void ProductController::list() {
    productRepository.read();
}

void ProductController::create() {
    Product p = makeProduct();

    p.setId(Util::getNextId());

    productRepository.write(p);
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

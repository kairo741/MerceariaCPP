#include "ProductController.h"
#include "Product.h"
#include "Util.h"
#include "ProductRepository.h"

int ProductController::menu() {
    return 0;
}

ProductController::ProductController(ProductRepository _productRepository) {
    productRepository = _productRepository;
}


void ProductController::list() {
    productRepository.read();
}

void ProductController::create() {}

void ProductController::update() {}

void ProductController::remove() {}

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
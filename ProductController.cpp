#include "ProductController.h"
#include "Product.h"
#include "Util.h"

int ProductController::menuProduct(){
    return 0;
}
void ProductController::showProduct(){}
void ProductController::registerProduct(){}
void ProductController::updateProduct(){}
void ProductController::deleteProduct(){}

void ProductController::ProductMenu()
{
    switch (menuProduct())
    {
    case 1:
        showProduct();
        Util::enterToContinue();
        break;

    case 2:
        registerProduct();
        Util::enterToContinue();
        break;

    case 3:
        updateProduct();
        Util::enterToContinue();
        break;

    case 4:
        deleteProduct();
        Util::enterToContinue();
        break;

    default:
        break;
    }
}
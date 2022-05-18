#ifndef _market_product_h_
#define _market_product_h_

#include "Util.h"

using namespace Util;

class Product {
private:
    int id{};
    char name[100]{};
    double price{};
    int quantity{};
public:
    explicit Product() = default;

    char* getProductName();

    void ProductMenu()
    {
        switch (menuProduct()) {
            case 1:
                showProduct();
                enterToContinue()
                break;

            case 2:
                registerProduct();
                enterToContinue();
                break;

            case 3:
                updateProduct();
                enterToContinue();
                break;

            case 4:
                deleteProduct();
                enterToContinue();
                break;

            default:
                break;
        }
    }
};

#endif
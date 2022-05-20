#ifndef _market_customer_controller_h_
#define _market_customer_controller_h_

#include "Product.h"
#include "Util.h"
#include "ProductRepository.h"
#include <stdio.h>

class ProductController{
private:
    ProductRepository customerRepository;

public:
    explicit ProductController() = default;

    int menuProduct();
    void showProduct();
    void registerProduct();
    void updateProduct();
    void deleteProduct();

    void ProductMenu();
};

#endif
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

    int menu();
    void list();
    void create();
    void update();
    void remove();

};

#endif
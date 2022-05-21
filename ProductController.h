#ifndef _market_customer_controller_h_
#define _market_customer_controller_h_

#include "Product.h"
#include "Util.h"
#include "ProductRepository.h"

class ProductController {
private:
    ProductRepository productRepository;

public:
    explicit ProductController(ProductRepository _productRepository);

    static int menu();

    void list();

    static void create();

    void update();

    void remove();

};

#endif
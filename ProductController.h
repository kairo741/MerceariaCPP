#ifndef _market_product_controller_h_
#define _market_product_controller_h_

#include "Product.h"
#include "ProductRepository.h"

class ProductController {
private:
    ProductRepository productRepository;
public:
    explicit ProductController(ProductRepository _productRepository);

    int menu();

    void list();

    void create();

    void update();

    void remove();

};

#endif
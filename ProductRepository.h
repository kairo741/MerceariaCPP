#ifndef _market_customer_repository_h_
#define _market_customer_repository_h_

#include "Product.h"
#include <stdio.h>

class ProductRepository {
private:
    const char *productFile = "products.bin";
    const char *productTempFile = "products_temp.bin";

public:
    explicit ProductRepository() = default;

    void read();
    void write(Product product);
    void replaceOrDelete(Product product, bool removeData = false);
};

#endif
#ifndef _market_product_h_
#define _market_product_h_

class Product {
private:
    int id{};
    char name[100]{};
    double price{};
    int quantity{};
public:
    explicit Product() = default;

    char* getProductName();
};

#endif
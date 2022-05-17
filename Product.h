#ifndef _market_product_h_
#define _market_product_h_

#include <string>

using namespace std;

class Product {
private:
    int id{};
    string name;
    double price{};
    int quantity{};
public:
    explicit Product() = default;

    string getProductName();
};

#endif
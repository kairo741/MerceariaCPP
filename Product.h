#ifndef _market_product_h_
#define _market_product_h_

#include "Util.h"

class Product {
private:
    int id;
    char name[100];
    double price;
    int quantity;
public:
    explicit Product(int _id, const char* _name, double _price, int _quantity);
    explicit Product() = default;

    int getId() const;

    void setId(int id);

    const char *getName() const;

    void setName(char* name);

    double getPrice() const;

    void setPrice(double price);

    int getQuantity() const;

    void setQuantity(int quantity);

};

#endif
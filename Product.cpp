#include "Product.h"
#include "Util.h"

char *Product::getProductName() {
    return name;
}

int Product::getId() const {
    return id;
}

void Product::setId(int id) {
    Product::id = id;
}

const char *Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    Product::price = price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

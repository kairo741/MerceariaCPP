#ifndef _market_sale_controller_h_
#define _market_sale_controller_h_

#include "ProductRepository.h"
#include "CustomerRepository.h"

class SaleController{
private:
    CustomerRepository customerRepository;
    ProductRepository productRepository;
public:
    explicit SaleController(CustomerRepository _customerRepository, ProductRepository _productRepository);

    int menu();

    void makeSale();
    void showTotalSpentPerCustomer();
};
#endif
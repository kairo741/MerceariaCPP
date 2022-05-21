#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <iostream>

#include "CustomerRepository.h"
#include "ProductRepository.h"
#include "Product.h"
#include "Customer.h"
#include "SaleController.h"



int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    Customer c = Customer(1, "nome", 20.0);
    Product p = Product(2, "nome produto", 20.0, 200);

    CustomerRepository cr = CustomerRepository();
    ProductRepository pr = ProductRepository();

    pr.write(p);
    // cr.write(c);

    SaleController sc = SaleController(cr, pr);

    sc.makeSale();
    

    return 0;
}
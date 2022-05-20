#ifndef _market_customer_controller_h_
#define _market_customer_controller_h_

#include "Customer.h"
#include "Util.h"
#include "CustomerRepository.h"
#include <stdio.h>

class CustomerController{
private:
    CustomerRepository customerRepository;

public:
    explicit CustomerController(CustomerRepository _customerRepository) = default;

    int menu();
    void list();
    void create();
    void update();
    void remove();

};

#endif
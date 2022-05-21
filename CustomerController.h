#ifndef _market_customer_controller_h_
#define _market_customer_controller_h_

#include "CustomerRepository.h"

class CustomerController{
private:
    CustomerRepository customerRepository;

public:
    explicit CustomerController(CustomerRepository _customerRepository);

    int menu();
    void list();
    void create();
    void update();
    void remove();

};

#endif
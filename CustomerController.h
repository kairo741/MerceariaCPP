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
    explicit CustomerController() = default;

    int menuCustomer();
    void showCustomer();
    void registerCustomer();
    void updateCustomer();
    void deleteCustomer();

    void CustomerMenu(){ 
        switch (menuCustomer()) {
            case 1:
                showCustomer();
                Util::enterToContinue();
                break;

            case 2:
                registerCustomer();
                Util::enterToContinue();
                break;

            case 3:
                updateCustomer();
                Util::enterToContinue();
                break;

            case 4:
                deleteCustomer();
                Util::enterToContinue();
                break;

            default:
                break;
        }
    }
};

#endif
#ifndef _market_customer_h_
#define _market_customer_h_

#include "Util.h"

class Customer {
private:
    int id;
    char name[50];
    double totalSpent;
public:
    explicit Customer() = default;

    char* getCustomerName();

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

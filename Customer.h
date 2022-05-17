#ifndef _market_customer_h_
#define _market_customer_h_

#include <string>
#include "Util.h"

using namespace std;
using namespace Util;

class Customer {
private:
    int id{};
    string name;
    double totalCost{};
public:
    explicit Customer() = default;

    string getCustomerName();

    void CustomerMenu()
    {
        switch (menuCustomer()) {
            case 1:
                showCustomer();
                enterToContinue()
                break;

            case 2:
                registerCustomer();
                enterToContinue();
                break;

            case 3:
                updateCustomer();
                enterToContinue();
                break;

            case 4:
                deleteCustomer();
                enterToContinue();
                break;

            default:
                break;
        }
    }
};



#endif

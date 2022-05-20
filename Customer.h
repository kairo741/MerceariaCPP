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

};

#endif
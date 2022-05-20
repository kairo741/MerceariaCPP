#ifndef _market_customer_h_
#define _market_customer_h_

#include "Util.h"
#include <string.h>
class Customer {
private:
    int id;
    char name[50];
    double totalSpent;
public:
    explicit Customer(int _id, const char* _name, double _totalSpent){
        id = _id;
        strcpy(name, _name);
        totalSpent = _totalSpent;
    };

};

#endif
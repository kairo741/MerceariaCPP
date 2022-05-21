#ifndef _market_customer_repository_h_
#define _market_customer_repository_h_

#include "Customer.h"

class CustomerRepository{
private:
    const char* customerFile = "customers.bin";
    const char* customerTempFile = "customers temp.bin";


public:  
    explicit CustomerRepository() = default;
    void readCustomers();
    void writeCustomers(Customer c);
    void replaceOrDeleteCustomer(Customer c, bool removeData=false);

};

#endif
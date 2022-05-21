#ifndef _market_customer_repository_h_
#define _market_customer_repository_h_

#include "Customer.h"

class CustomerRepository{
private:
    const char* customerFile = "customers.bin";
    const char* customerTempFile = "customers_temp.bin";

public:  
    explicit CustomerRepository() = default;
    void read();
    void write(Customer c);
    void replaceOrDelete(Customer c, bool removeData=false);
    Customer getById(int id);
};

#endif
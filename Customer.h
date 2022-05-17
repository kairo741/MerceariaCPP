#ifndef _market_customer_h_
#define _market_customer_h_

#include <string>

using namespace std;

class Customer {
private:
    int id{};
    string name;
    double totalCost{};
public:
    explicit Customer() = default;

    string getCustomerName();
};

#endif

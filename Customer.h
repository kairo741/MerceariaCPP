#ifndef _market_customer_h_
#define _market_customer_h_

class Customer {
private:
    int id;
    char name[50];
    double totalSpent;
public:
    explicit Customer(int _id, const char* _name, double _totalSpent);
    explicit Customer();
    char* getName();
    int getId();
    double getTotalSpent();
    void setName(char* _name);
    void setId(int _id);
    void setTotalSpent(double _totalSpent);

};

#endif
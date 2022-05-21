#include "Customer.h"
#include <string.h>

char* Customer::getName() {
    return name;
}

int Customer::getId(){
    return id;
}

double Customer::getTotalSpent(){
    return totalSpent;
}

void Customer::setName(char* _name){
    strcpy(name, _name);
}

void Customer::setId(int _id){
    id = _id;
}

void Customer::setTotalSpent(double _totalSpent){
    totalSpent = _totalSpent;
}

Customer::Customer(int _id, const char* _name, double _totalSpent){
    id = _id;
    strcpy(name, _name);
    totalSpent = _totalSpent;
};


#include "Util.h"
#include "CustomerController.h"

CustomerControler::CustomerController(CustomerRepository _customerRepository) {
    customerRepository = _customerRepository;
};

int CustomerController::menu(){
    return 0;
}
void CustomerController::list(){}
void CustomerController::create(){}
void CustomerController::update(){}
void CustomerController::remove(){}

// void mainCustomerMenu()
// {
//     // switch (menu())
//     // {
//     // case 1:
//     //     showCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 2:
//     //     registerCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 3:
//     //     updateCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // case 4:
//     //     deleteCustomer();
//     //     Util::enterToContinue();
//     //     break;

//     // default:
//     //     break;
//     // }
// }
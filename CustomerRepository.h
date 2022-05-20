#ifndef _market_customer_repository_h_
#define _market_customer_repository_h_

#include "Customer.h"
#include <stdio.h>
#include "Util.h"
#include <iostream>


class CustomerRepository{
private:
    const char* customerFile = "customers.bin";
    const char* customerTempFile = "customers temp.bin";

public:  
    explicit CustomerRepository() = default;
    
    void readCustomers(){
        FILE *filePointer;

        filePointer = fopen(customerFile, "rb");
        Customer buffer;

        fseek(filePointer, 0, SEEK_SET);

        while (true){
            fread(&buffer, sizeof(buffer), 1, filePointer);
            if (feof(filePointer)){
                break;
            }

            Util::getUpLines();
            printf("   Id: %d\n", buffer.getId());
            printf("   Nome: %s\n", buffer.getName());
            printf("   Total Gasto: %f.2", buffer.getTotalSpent());
            Util::getUnderLines();
        }

        fclose(filePointer);
    }


    void writeCustomers(Customer c){
        FILE *filePointer;
        filePointer = fopen(customerFile, "ab");

        fwrite(&c, 1, sizeof(c), filePointer);
        fclose(filePointer);
    }


    void replaceOrDeleteCustomer(Customer c, bool removeData=false){
        FILE *filePointer;
        filePointer = fopen(customerFile, "rb");
        Customer buffer;
        fseek(filePointer, 0, SEEK_SET);

        FILE *newFilePointer;
        newFilePointer = fopen(customerTempFile, "ab");
        Customer newBuffer;

        while (true){
            fread(&buffer, sizeof(buffer), 1, filePointer);

            if (feof(filePointer)){
                break;
            }

             if (buffer.getId() == c.getId()){
                 if (!removeData){
                     fwrite(&c, 1, sizeof(c), newFilePointer);
                 }
             }
             else{
                 fwrite(&buffer, 1, sizeof(buffer), newFilePointer);
             }
        }

        fclose(filePointer);
        fclose(newFilePointer);
        remove(customerFile);
        rename(customerTempFile, customerFile);
    }
};

#endif
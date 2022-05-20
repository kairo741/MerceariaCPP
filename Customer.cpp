#include "Customer.h"
#include <stdio.h>


const char* customerFile = "customers.bin";
const char* customerTempFile = "customers temp.bin";

char* Customer::getCustomerName() {
    return nullptr;
}


void registerCustomer(){
}

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
        // printar cliente aqui
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

        // descomentar quando estiver definido os getters e setters
        // if (buffer.id == c.id){
        //     if (!removeData){
        //         fwrite(&c, 1, sizeof(c), newFilePointer);
        //     }
        // }
        // else{
        //     fwrite(&buffer, 1, sizeof(buffer), newFilePointer);
        // }
    }

    fclose(filePointer);
    fclose(newFilePointer);
    remove(customerFile);
    rename(customerTempFile, customerFile);
}


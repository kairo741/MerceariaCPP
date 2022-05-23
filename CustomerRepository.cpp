#include "CustomerRepository.h"
#include "Util.h"
#include <stdio.h>

void CustomerRepository::read(){
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
        printf("   Total Gasto: %.2f", buffer.getTotalSpent());
        Util::getUnderLines();
    }

    fclose(filePointer);
}


void CustomerRepository::write(Customer c){
    FILE *filePointer;
    filePointer = fopen(customerFile, "ab");

    fwrite(&c, 1, sizeof(c), filePointer);
    fclose(filePointer);
}


void CustomerRepository::replaceOrDelete(Customer c, bool removeData){
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

Customer CustomerRepository::getById(int id){
    FILE *filePointer;

    filePointer = fopen(customerFile, "rb");
    Customer buffer;

    fseek(filePointer, 0, SEEK_SET);

    while (true){
        fread(&buffer, sizeof(buffer), 1, filePointer);
        if (feof(filePointer)){
            break;
        }
        if (buffer.getId() == id){
            fclose(filePointer);
            return buffer;
        }
    }
    fclose(filePointer);
    return Customer();
}
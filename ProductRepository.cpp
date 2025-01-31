#include "ProductRepository.h"
#include "Product.h"
#include <stdio.h>

void ProductRepository::read() {
    FILE *filePointer;

    filePointer = fopen(productFile, "rb");
    Product buffer;

    fseek(filePointer, 0, SEEK_SET);

    while (true) {
        fread(&buffer, sizeof(buffer), 1, filePointer);
        if (feof(filePointer)) {
            break;
        }
        // todo - printar produto aqui
        Util::getUpLines();
        printf("   Id: %d\n", buffer.getId());
        printf("   Nome: %s\n", buffer.getName());
        printf("   Preço: %.2f\n", buffer.getPrice());
        printf("   Quantidade: %d", buffer.getQuantity());
        Util::getUnderLines();
    }

    fclose(filePointer);
}


void ProductRepository::write(Product product) {
    FILE *filePointer;
    filePointer = fopen(productFile, "ab");

    fwrite(&product, 1, sizeof(product), filePointer);
    fclose(filePointer);
}


void ProductRepository::replaceOrDelete(Product product, bool removeData) {
    FILE *filePointer;
    filePointer = fopen(productFile, "rb");
    Product buffer;
    fseek(filePointer, 0, SEEK_SET);

    FILE *newFilePointer;
    newFilePointer = fopen(productTempFile, "ab");
    Product newBuffer;

    while (true) {
        fread(&buffer, sizeof(buffer), 1, filePointer);

        if (feof(filePointer)) {
            break;
        }

        
        if (buffer.getId() == product.getId()){
            if (!removeData){
                fwrite(&product, 1, sizeof(product), newFilePointer);
            }
        }
        else{
            fwrite(&buffer, 1, sizeof(buffer), newFilePointer);
        }
    }

    fclose(filePointer);
    fclose(newFilePointer);
    remove(productFile);
    rename(productTempFile, productFile);
}

Product ProductRepository::getById(int id){
    FILE *filePointer;

    filePointer = fopen(productFile, "rb");
    Product buffer;

    fseek(filePointer, 0, SEEK_SET);

    while (true) {
        fread(&buffer, sizeof(buffer), 1, filePointer);
        if (feof(filePointer)) {
            break;
        }
        if (buffer.getId() == id){
            fclose(filePointer);
            return buffer;
        }
    }

    fclose(filePointer);
    return Product();
}
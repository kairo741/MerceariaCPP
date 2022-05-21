#include "Util.h"
#include <stdio.h>
#include <algorithm>

#define upLines "\n╭──────────────────────────╮\n"
#define underLines "\n╰──────────────────────────╯\n"

void Util::clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system ("clear");
#endif
}

void Util::enterToContinue() {
    printf("\n\nPressione ENTER para continuar...");
    if (getchar() == '\n') {
        getchar();
    }
}

int getCounterFromFile(){
    FILE *filePointer;

    filePointer = fopen("counter.bin", "rb");
    int counter = 1;

    if (filePointer == NULL){
        filePointer = fopen("counter.bin", "wb");
        fwrite(&counter, 1, sizeof(counter), filePointer);

        fclose(filePointer);
        return counter;
    }
    else{
        fseek(filePointer, 0, SEEK_SET);
        fread(&counter, sizeof(counter), 1, filePointer);
        counter+=1;

        fclose(filePointer);

        filePointer = fopen("counter.bin", "wb");
        fwrite(&counter, 1, sizeof(int), filePointer);
        fclose(filePointer);

        return counter;
    }
}

int Util::getNextId() {
    return getCounterFromFile();
}



void Util::getUpLines() {
    printf(upLines);
}

void Util::getUnderLines() {
    printf(underLines);
}
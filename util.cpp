#include <stdio.h>
#include <algorithm>

#ifndef _arquivo_util_cpp_
#define _arquivo_util_cpp_

#define linhasDeCima "\n╭──────────────────────────╮\n"
#define linhasDeBaixo "\n╰──────────────────────────╯\n"

int idCounter = 0;

int getNextId() {
    idCounter += 1;
    return idCounter;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system ("clear");
#endif
}

void enterToContinue() {
    printf("Pressione ENTER para continuar...");
    fflush(stdin);
    getchar();
}


#endif
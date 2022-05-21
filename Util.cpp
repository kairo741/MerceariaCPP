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

int Util::getNextId() {
    // id++;
    return 1;
}

void Util::getUpLines() {
    printf(upLines);
}

void Util::getUnderLines() {
    printf(underLines);
}
#include <Util.h>
#include <stdio.h>
#include <algorithm>

#define linhasDeCima "\n╭──────────────────────────╮\n"
#define linhasDeBaixo "\n╰──────────────────────────╯\n"
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
    printf("Pressione ENTER para continuar...");
    if (getchar() == '\n') {
        getchar();
    }
}

void Util::getUpLines(){
    printf(upLines)
}
void Util::getUnderLines(){
    printf(underLines)
}
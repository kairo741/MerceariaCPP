#include <Util.h>

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

int Util::getNextId() {
    id++;
    return id;
}

void Util::getUpLines() {
    printf(upLines);
}

void Util::getUnderLines() {
    printf(underLines);
}
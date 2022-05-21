#ifndef _market_util_h_
#define _market_util_h_

class Util {
    static int id;
public:

    static int getNextId();

    static void clearTerminal();

    static void enterToContinue();

    static void getUpLines();

    static void getUnderLines();
};

#endif
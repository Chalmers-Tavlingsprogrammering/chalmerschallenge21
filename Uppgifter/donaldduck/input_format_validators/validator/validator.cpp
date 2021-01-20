#include "validator.h"

void run() {
    int maxN = 1000000;
    int maxM = 1000000;

    int N = Int(0, maxN);
    Space();
    int M = Int(0, maxM);
    Endl();

    assert(N != M);

    Eof();
}

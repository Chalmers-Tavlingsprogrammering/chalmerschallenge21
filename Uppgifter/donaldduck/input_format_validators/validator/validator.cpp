#include "validator.h"

void run() {
    int maxN = 1000000;
    int maxM = 1000000;

    int N = Int(1, maxN-1);
    Space();
    int M = Int(1, maxM-1);
    Endl();

    assert(N != M);
    assert(N % 10 != 0);
    assert(M % 10 != 0);

    Eof();
}

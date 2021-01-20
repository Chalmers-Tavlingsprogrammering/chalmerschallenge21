#include "validator.h"

void run() {
    int max_N = 1e5;
    int max_page = 1 << 26;

    int N = Int(0, max_N);
    Endl();
    for (int i = 0; i < N; i++) {
        Int(0, max_page - 1);
        Endl();
    }
}

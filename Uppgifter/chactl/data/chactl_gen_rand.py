#!/usr/bin/env python3
import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

max_N = int(cmdlinearg("max_N", 1e5))
max_page = int(cmdlinearg("max_page", 2**26))

N = random.randint(1, max_N)
print(N)

for _ in range(N):
    print(random.randrange(1, max_page))

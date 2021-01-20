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

n = int(cmdlinearg('n'))
print(n)

a = [random.randint(2, n)]
for i in range(1, n): a.append(1)
print(' '.join(map(str, a)))

b = [random.randint(0, 10000000) for i in range(n)]
b[0] = -1000000000
print(' '.join(map(str, b)))

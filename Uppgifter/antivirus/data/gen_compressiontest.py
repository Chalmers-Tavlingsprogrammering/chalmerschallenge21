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

b = [0]*n
a = [2]
for i in range(1, (n-1)//2):
    a.append(i)
l = len(a)
while(len(a) < n):
    b[len(a)] = random.randint(1, 100)
    a.append(l-random.randint(0,2))
b[0] = -sum(b)
print(' '.join(map(str, a)))
print(' '.join(map(str, b)))

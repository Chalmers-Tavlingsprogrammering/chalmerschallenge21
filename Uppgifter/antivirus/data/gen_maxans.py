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

a = [n]
for i in range(1, n): a.append(i)
print(' '.join(map(str, a)))

start = int(cmdlinearg("start", random.randint(0, n)))
b = [1]*n
for i in range(1, n):
    b[(start-i+n)%n] = b[(start-i+n+1)%n]
    if((start-i+n)%n == n-1 or random.uniform(0, 1) < 15/n):
        b[(start-i+n)%n] += 1
b[start] = 0
b[start] = -sum(b)+random.randint(0, 2)

print(' '.join(map(str, b)))

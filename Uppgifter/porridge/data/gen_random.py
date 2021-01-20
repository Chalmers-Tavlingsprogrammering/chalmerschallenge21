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
max_M = int(cmdlinearg("max_M", 1e9))
max_I = int(cmdlinearg("max_I", 1e9))
prob_same = int(cmdlinearg("prob_same", 0))

N = random.randint(1, max_N)
M = random.randint(1, max_M)
impatience = []

for j in range(N):
    if len(impatience) != 0 and random.random() < prob_same:
        impatience.append(impatience[-1])
    else:
        I = random.randint(1, max_I)
        impatience.append(I)

print(N, M)
print(' '.join(map(str, impatience)))

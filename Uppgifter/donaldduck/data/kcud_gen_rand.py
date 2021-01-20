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

max_N = int(cmdlinearg("max_N", 1e6))
max_M = int(cmdlinearg("max_M", 1e6))

while True:
    n = random.randint(0, max_N)
    m = random.randint(0, max_M)
    if n != m:
        break

print(n, m)

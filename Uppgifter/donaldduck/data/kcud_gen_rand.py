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

max_N = cmdlinearg("max_N", 1e6)
max_M = cmdlinearg("max_M", 1e6)

print(max_N, max_M)

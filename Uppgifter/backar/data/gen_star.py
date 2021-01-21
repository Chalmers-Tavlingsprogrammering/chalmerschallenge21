#!/usr/bin/env python3

import sys
sys.setrecursionlimit(1000000)
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n = int(cmdlinearg('n'))

center = random.randrange(0, n)

heights = [random.randrange(-1e5, 1e5) for _ in range(n)]
heights[center] = random.randrange(-1e5, 0)
end_idx = max((h, i) for i, h in enumerate(heights))[1]

print(n, n - 1)
print(center + 1, end_idx + 1)
print(" ".join(map(str, heights)))

order = list(range(n))
random.shuffle(order)
for i in order:
    if i == center: continue

    if random.random() < 0.5:
        print(i + 1, center + 1)
    else:
        print(center + 1, i + 1)

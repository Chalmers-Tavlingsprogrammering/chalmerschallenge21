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
m = int(cmdlinearg('m'))

connections = [set() for _ in range(n)]
for _ in range(m):
    a, b = -1, -1
    while a == b or b in connections[a] or a in connections[b]:
        a, b = random.randrange(0, n), random.randrange(0, n)
    connections[a].add(b)
    connections[b].add(a)

def dfs(connections, visited, at):
    res = set([at])
    if at in visited:
        return res
    visited.add(at)

    for b in connections[at]:
        res.update(dfs(connections, visited, b))

    return res

not_reached = set(range(n))
while len(not_reached) > 0:
    start = list(not_reached)[0]
    reachable = dfs(connections, set(), start)
    not_reached = not_reached.difference(reachable) # will remove start

    if len(reachable) > 2:
        start = random.choice(list(reachable))
        reachable.remove(start)
        end = random.choice(list(reachable))
        break

print(n, m)
print(start + 1, end + 1)
print(" ".join(str(random.randrange(-1e5, 1e5)) for _ in range(n)))

connections = set(
    (min(a, b), max(a, b))
    for a in range(n)
    for b in connections[a]
)

connections = list(connections)
random.shuffle(connections)

for a, b in connections:
    if random.random() < 0.5:
        print(a + 1, b + 1)
    else:
        print(b + 1, a + 1)

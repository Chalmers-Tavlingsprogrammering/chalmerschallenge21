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

min_b = int(cmdlinearg('min_b', -1000000000))
max_b = int(cmdlinearg('max_b',  1000000000))
circlesize = int(cmdlinearg('circlesize', max(n//2, 2)))

print(n)

a = [random.randint(1, n-1)]
for i in range(1, n): a.append(random.randint(0, i-1))

circle = random.sample(range(1, n), circlesize-1)
circle.append(0)
circle.sort()
for i in range(circlesize):
    a[circle[i]] = circle[(i-1+circlesize)%circlesize]

incircle = [False]*n
for i in circle: incircle[i] = 1

inc = [[] for i in range(n)]
for i in range(n):
    inc[a[i]].append(i)

order = []
sending = [None]*n
def dfs(v):
    if(sending[v] != None): return
    sending[v] = 0
    for i in inc[v]:
        dfs(i)
    order.append(v)

for i in range(n):
    if(not incircle[i]):
        dfs(i)

b = [0 for i in range(n)]
for i in order:
    for j in inc[i]: sending[i] += sending[j]
    b[i] = random.randint(max(min_b, -sending[i]), max_b)
    sending[i] += b[i]

amt = -sum(b)
if(amt < min_b*len(circle)):
    for i in circle:
        b[i] = random.randint(min_b, random.randint(min_b, max_b))
else:
    start = amt//len(circle)
    for i in circle: b[i] = start
    amt = -sum(b)
    for i in range(amt):
        b[circle[i]] += 1
    for i in range(len(circle)*2):
        ind1 = random.choice(circle)
        ind2 = random.choice(circle)
        if(ind1 == ind2): continue
        send = random.randint(-min(b[ind2]-min_b, max_b-b[ind1]), min(b[ind1]-min_b, max_b-b[ind2]))
        b[ind1] -= send
        b[ind2] += send

for i in range(n):
    assert(min_b <= b[i] <= max_b)

a = [i+1 for i in a]
print(' '.join(map(str, a)))
print(' '.join(map(str, b)))

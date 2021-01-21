#!/usr/bin/env python3
import heapq

n, m = [int(x) for x in input().split()]
start, end = [int(x) - 1 for x in input().split()]
heights = [int(x) for x in input().split()]

conns = [set() for _ in range(n)]
for _ in range(m):
    fr, to = [int(x) for x in input().split()]
    fr -= 1; to -= 1

    conns[fr].add(to)
    conns[to].add(fr)

heap = [(0, start)]
visited = set()
while len(heap) > 0:
    dist, i = heapq.heappop(heap)

    if i in visited:
        continue
    visited.add(i)

    if i == end:
        print(dist)
        break

    height_here = heights[i]
    for conn in conns[i]:
        height_there = heights[conn]

        diff = height_there - height_here
        diff = max(0, diff)
        heapq.heappush(heap, (dist + diff, conn))

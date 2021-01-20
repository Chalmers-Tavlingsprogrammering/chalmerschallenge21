N, M = [int(q) for q in input().split()]
impatience = [int(q) for q in input().split()]
impatience.sort()
porridges = []

for i in range(N):
    T = impatience[i]
    if T < M + 2:
        porridges.append(min(N-i, T//2))
    else:
        cold = max(0, (T-M)//2)
        extra = (T - M) % 2
        reheats = min(M - extra, cold)
        final_new = max(0, (M - extra - reheats)//2)
        porridges.append(min(N-i, extra + reheats + final_new))

print(max(porridges))

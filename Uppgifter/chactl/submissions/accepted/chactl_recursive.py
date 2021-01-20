N = int(input())

# The number of 2-pow jumps required to jump n pages
def jumps_required(n):
    assert n >= 0

    if n == 0:
        return 0
    if n == 1:
        return 1
    if n % 2 == 0:
        return jumps_required(n // 2)
    if n % 4 == 1:
        return 1 + jumps_required(n // 4)
    if n % 4 == 3:
        return 1 + jumps_required(n // 4 + 1)

at = 0
ans = 0
for _ in range(N):
    P = int(input())
    ans += jumps_required(abs(at - P))
    at = P

print(ans)

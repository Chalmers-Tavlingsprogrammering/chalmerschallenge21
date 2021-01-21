N = int(input())

# The number of 2-pow jumps required to jump n pages
def jumps_required(n):
    assert n >= 0

    jumpsize = 2**26
    ans = 0
    while n > 0:
        while abs(n - jumpsize) > abs(n - jumpsize // 2):
            jumpsize //= 2
        ans += 1
        n = abs(n - jumpsize)
    return ans

at = 0
ans = 0
for _ in range(N):
    P = int(input())
    ans += jumps_required(abs(at - P))
    at = P

print(ans)

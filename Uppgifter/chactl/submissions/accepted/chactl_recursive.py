N = int(input())

# f(0) = 0
# f(2k) = f(k)
# f(4k + 1) = 1 + f(k)
# f(4k + 3) = 1 + f(k+1)
def jumps_required(n):
    assert n >= 0
    ans = 0
    while n > 0:
        if n % 2 == 0:
            n //= 2
        elif n % 4 == 1:
            ans += 1
            n = n // 4
        else:
            ans += 1
            n = n // 4 + 1
    return ans

at = 0
ans = 0
for _ in range(N):
    P = int(input())
    ans += jumps_required(abs(at - P))
    at = P

print(ans)

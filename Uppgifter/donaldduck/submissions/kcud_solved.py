n,m = [str(x) for x in input().split()]
n2 = ""
m2 = ""

for i in n:
    if i == '2':
        n2 += '5'
    elif i == '5':
        n2 += '2'
    else:
        n2 += i

for j in m:
    if j == '2':
        m2 += '5'
    elif j == '5':
        m2 += '2'
    else:
        m2 += j

m2 = m2[::-1]
n2 = n2[::-1]

if  int(n2) > int(m2):
    print(1)
else:
    print(2)

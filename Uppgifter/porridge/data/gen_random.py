from random import randint

N = randint(1, 100000)
M = randint(1, 1000000000)
impatience = []

for j in range(N):
    I = randint(1, 1000000000)
    impatience.append(I)

print(' '.join(map(str, impatience)))

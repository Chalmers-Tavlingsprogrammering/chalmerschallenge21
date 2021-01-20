#!/bin/env python3
n,m = [str(x) for x in input().split()]

def reversing(x):
    x2 = ""
    for i in x:
        if i == '2':
            x2 += '5'
        elif i == '5':
            x2 += '2'
        else:
            x2 += i
    return(x2[::-1])

if int(reversing(n)) > int(reversing(m)):
    print(1)
else:
    print(2)

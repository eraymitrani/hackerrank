#!/bin/python3

import sys

def getMagicNumber(s, k, b, m):
    # Complete this function
    size = len(s)
    sum = 0
    for i in range(0, size - k + 1):
        sum+= int(s[i:i+k], b) % m        

    return sum

s = input().strip()
k, b, m = input().strip().split(' ')
k, b, m = [int(k), int(b), int(m)]
result = getMagicNumber(s, k, b, m)
print(result)

#!/bin/python

import sys

if __name__ == "__main__":
    n, m = raw_input().strip().split(' ')
    n, m = [int(n), int(m)]
    book = {}
    total = 0
    for i in range(1,m + 1):
        book[i] = 0
    for a0 in xrange(n):
        id_number, amount = raw_input().strip().split(' ')
        id_number, amount = [int(id_number), int(amount)]
        book[id_number] += amount
        total+=amount
    pay = int(total / m)
    print('1 ' + str(book[1] - (total - pay * m) - pay))
    for i in range(2,m+1):
        print(str(i) + ' ' + str(int(book[i] - pay)))

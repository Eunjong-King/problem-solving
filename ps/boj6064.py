import math
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    M, N, x, y = map(int, sys.stdin.readline().split(' '))

    myLcm = math.lcm(M, N)

    if M == x and N == y:
        print(myLcm)
        continue

    if N > M:
        M, N = N, M
        x, y = y, x

    if M == x:
        x = 0
    if N == y:
        y = 0



    i = 0
    breaker = False
    while M*i <= myLcm:
        if((M * i + x) % N == y):
            print(M * i + x)
            breaker = True
            break
        i += 1

    if not breaker:
        print(-1)
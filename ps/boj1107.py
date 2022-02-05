import sys
from copy import deepcopy

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

if M != 0:
    btn_list = set(sys.stdin.readline().strip().split(' '))
else:
    btn_list = set()

if M == 10:
    print(abs(N-100))
    exit(0)

if N == 100:
    print(0)
elif N < 100:
    sN = deepcopy(N)
    bN = deepcopy(N)
    count = 500100
    while sN >= 0:
        if len(btn_list & set(str(sN))) == 0:
            count = (N - sN) + len(str(sN))
            break
        sN -= 1
    while bN < 100:
        if len(btn_list & set(str(bN))) == 0:
            temp_count = len(str(bN)) + (bN - N)
            if count > temp_count:
                count = temp_count
            break
        bN += 1
    if count > (100 - N):
        count = 100 - N

    print(count)

else:
    sN = deepcopy(N)
    bN = deepcopy(N)
    until = N - 100 + N
    count = 500100
    while sN > 100:
        if len(btn_list & set(str(sN))) == 0:
            count = (N - sN) + len(str(sN))
            break
        sN -= 1
    while bN < until:
        if len(btn_list & set(str(bN))) == 0:
            temp_count = len(str(bN)) + (bN - N)
            if count > temp_count:
                count = temp_count
            break
        bN += 1
    if count > (N - 100):
        count = N - 100
    print(count)
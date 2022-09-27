import sys

N, r, c = map(int, sys.stdin.readline().split())

answer = 0
for i in range(N, 0, -1):
    if r >= (2 ** (i-1)):
        if c >= (2 ** (i-1)):
            answer += (2 ** ((i-1)*2)) * 3
            r -= (2 ** (i-1))
            c -= (2 ** (i-1))
        else:
            answer += (2 ** ((i-1)*2)) * 2
            r -= (2 ** (i-1))
    else:
        if c >= (2 ** (i - 1)):
            answer += (2 ** ((i-1) *2)) * 1
            c -= (2 ** (i-1))
        else:
            pass

print(answer)
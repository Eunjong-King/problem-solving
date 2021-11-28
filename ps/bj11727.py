import sys

N= int(sys.stdin.readline())

start = 1

for i in range(2, N+1):
    if i % 2 == 0:
        start = start * 2 + 1
        start %= 10007
    else:
        start = start * 2 - 1
        start %= 10007

print(start)
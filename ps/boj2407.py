from copy import deepcopy

n, m = map(int, input().split(' '))

if m > (n / 2):
    m = n - m

up = 1
down = 1
ind = deepcopy(m)
for _ in range(ind):
    up *= n
    if up % m == 0 and m > 0:
        up //= m
        m -= 1
    n -= 1

while m != 0:
    up //= m
    m-=1

print(up)
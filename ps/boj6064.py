import sys
import math

T = int(sys.stdin.readline())

for _ in range(T):
    M, N, x, y = map(int, sys.stdin.readline().split())
    lcm = (M * N) // math.gcd(M, N)

    x_list = []
    
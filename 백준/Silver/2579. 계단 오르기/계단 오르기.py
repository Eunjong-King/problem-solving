import sys

input = sys.stdin.readline

N = int(input())

li = [0 for _ in range(N)]
for i in range(N):
    li[i] = int(input())

if N == 1:
    print(li[0])
elif N == 2:
    print(li[0] + li[1])
else:
    dp = [0 for _ in range(N)]
    dp[0] = li[0]
    dp[1] = li[0] + li[1]
    dp[2] = max(li[0] + li[2], li[1] + li[2])

    for i in range(3, N):
        dp[i] = max(dp[i - 3] + li[i - 1] + li[i], dp[i - 2] + li[i])

    print(dp[N - 1])

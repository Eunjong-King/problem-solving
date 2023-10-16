import heapq
import sys

input = sys.stdin.readline

N = int(input())

li = [['0' for _ in range(N)] for _ in range(N)]

for i in range(N):
    inp = input().rstrip()

    for j, c in enumerate(inp):
        li[i][j] = c

q = []
heapq.heappush(q, (0, 0, 0))

distances = [[3000 for _ in range(N)] for _ in range(N)]
distances[0][0] = 0 if li[0][0] == '1' else 1

adders = [[-1, 0], [1, 0], [0, -1], [0, 1]]

while q:
    now_i, now_j, now_cost = heapq.heappop(q)

    if distances[now_i][now_j] < now_cost:
        continue

    for adder in adders:
        new_i = now_i + adder[0]
        new_j = now_j + adder[1]

        if 0 <= new_i < N and 0 <= new_j < N:
            new_cost = (now_cost + 1) if li[new_i][new_j] == '0' else now_cost

            if distances[new_i][new_j] > new_cost:
                distances[new_i][new_j] = new_cost
                heapq.heappush(q, (new_i, new_j, new_cost))

print(distances[N - 1][N - 1])

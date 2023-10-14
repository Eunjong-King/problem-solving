import heapq
import sys

input = sys.stdin.readline

N, M, K, X = map(int, input().split())

data = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B = map(int, input().split())

    data[A].append(B)

result = [400000 for _ in range(N + 1)]
q = []
heapq.heappush(q, (0, X))
result[X] = 0

while q:
    cost, node = heapq.heappop(q)

    if result[node] < cost:
        continue

    for new_node in data[node]:
        if cost + 1 < result[new_node]:
            result[new_node] = cost + 1
            heapq.heappush(q, (cost + 1, new_node))

isNoValue = True
for idx, value in enumerate(result):
    if value == K:
        print(idx)
        isNoValue = False

if isNoValue:
    print(-1)

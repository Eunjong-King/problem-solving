import heapq
import sys

input = sys.stdin.readline

N = int(input())
M = int(input())

li = [[] for _ in range(N + 1)]

for _ in range(M):
    A, B, C = map(int, input().split())
    li[A].append([B, C])

A, B = map(int, input().split())

q = []
heapq.heappush(q, (A, 0))

distances = [200000000 for _ in range(N + 1)]
distances[A] = 0

history = [0 for _ in range(N + 1)]

while q:
    now_node, now_cost = heapq.heappop(q)

    if distances[now_node] < now_cost:
        continue

    for next_node, bus_cost in li[now_node]:
        next_cost = now_cost + bus_cost

        if distances[next_node] > next_cost:
            distances[next_node] = next_cost
            history[next_node] = now_node
            heapq.heappush(q, (next_node, next_cost))

print(distances[B])

result = [B]
while True:
    before_node = history[B]
    result.append(before_node)

    if before_node == A:
        break

    B = before_node

print(len(result))

result.reverse()
for i in result:
    print(i, end=' ')
print()

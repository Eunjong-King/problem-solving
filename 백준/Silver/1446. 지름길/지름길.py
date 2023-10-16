import heapq
import sys

input = sys.stdin.readline

N, D = map(int, input().split())

li = [[] for _ in range(D + 1)]

for _ in range(N):
    A, B, C = map(int, input().split())

    if A <= D and B <= D:
        li[A].append([B, C])

q = []
heapq.heappush(q, (0, 0))

distances = [30000 for _ in range(0, D + 1)]
distances[0] = 0

while q:
    now_cost, now_node = heapq.heappop(q)

    if distances[now_node] < now_cost:
        continue

    if now_node < D and distances[now_node + 1] > now_cost + 1:
        distances[now_node + 1] = now_cost + 1
        heapq.heappush(q, (now_cost + 1, now_node + 1))

    for shortcut_node, shortcut_cost in li[now_node]:
        new_cost = shortcut_cost + now_cost

        if distances[shortcut_node] > new_cost:
            distances[shortcut_node] = new_cost
            heapq.heappush(q, (new_cost, shortcut_node))

print(distances[D])

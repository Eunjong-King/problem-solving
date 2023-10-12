import heapq


def dijkstra(start):
    q = []
    distance = [1000000] * (N + 1)

    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for node_index, node_cost in graph[now]:
            cost = dist + node_cost

            if distance[node_index] > cost:
                distance[node_index] = cost
                heapq.heappush(q, (cost, node_index))

    return distance


N, M, X = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    A, B, T = map(int, input().split())
    graph[A].append([B, T])

result = 0
for i in range(1, N + 1):
    first = dijkstra(i)
    second = dijkstra(X)
    result = max(result, first[X] + second[i])

print(result)

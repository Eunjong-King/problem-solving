import heapq
import sys


def dijkstra(li, N) -> int:
    distances = [[200000 for _ in range(N)] for _ in range(N)]
    distances[0][0] = li[0][0]
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    q = []
    heapq.heappush(q, (li[0][0], 0, 0))

    while q:
        now_cost, now_i, now_j = heapq.heappop(q)

        if distances[now_i][now_j] < now_cost:
            continue

        for direction in directions:
            new_i = now_i + direction[0]
            new_j = now_j + direction[1]

            if 0 <= new_i < N and 0 <= new_j < N:
                new_cost = now_cost + li[new_i][new_j]

                if distances[new_i][new_j] > new_cost:
                    heapq.heappush(q, (new_cost, new_i, new_j))
                    distances[new_i][new_j] = new_cost

    return distances[N - 1][N - 1]


input = sys.stdin.readline
problem = 1
while True:
    N = int(input())

    if N == 0:
        break

    li = [[] for _ in range(N)]

    for i in range(N):
        li[i] = list(map(int, input().split()))

    result = dijkstra(li, N)

    print(f"Problem {problem}: {result}")
    problem += 1

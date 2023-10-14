N, M = map(int, input().split())

arr = [[0 for _ in range(N)] for _ in range(M)]
isVisited = [[False for _ in range(N)] for _ in range(M)]
count = [[0 for _ in range(N)] for _ in range(M)]

for i in range(M):
    row = input()
    for idx, j in enumerate(row):
        arr[i][idx] = j

q = [(0, 0, 0)]
count[0][0] = 0
isVisited[0][0] = True

adders = [(-1, 0), (1, 0), (0, -1), (0, 1)]

while len(q) > 0:
    a, b, cost = q.pop(0)

    for adder in adders:
        new_a = a + adder[0]
        new_b = b + adder[1]

        if 0 <= new_a < M and 0 <= new_b < N:
            new_cost = cost if arr[new_a][new_b] == '0' else cost + 1

            if isVisited[new_a][new_b] is False:
                isVisited[new_a][new_b] = True
                q.append((new_a, new_b, new_cost))
                count[new_a][new_b] = new_cost
            else:
                if count[new_a][new_b] <= new_cost:
                    continue
                else:
                    count[new_a][new_b] = new_cost
                    q.append((new_a, new_b, new_cost))

print(count[M - 1][N - 1])

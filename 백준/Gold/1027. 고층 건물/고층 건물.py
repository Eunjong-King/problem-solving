import sys

input = sys.stdin.readline


def isOk(i, j):
    x_diff = j - i
    y_diff = buildings[j] - buildings[i]

    result = True
    for k in range(i + 1, j):
        if buildings[k] != buildings[i]:
            if y_diff * (k - i) <= (buildings[k] - buildings[i]) * x_diff:
                result = False
                break
        else:
            if y_diff * (k - j) <= (buildings[k] - buildings[j]) * x_diff:
                result = False
                break

    return result


N = int(input())

buildings = list(map(int, input().split()))
results = [0 for _ in range(N)]

for i in range(N - 1):
    for j in range(i + 1, N):
        if isOk(i, j):
            results[i] += 1
            results[j] += 1

print(max(results))

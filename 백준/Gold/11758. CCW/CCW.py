import sys

input = sys.stdin.readline

P1 = list(map(int, input().split()))
P2 = list(map(int, input().split()))
P3 = list(map(int, input().split()))

if P1[0] == P2[0]:
    if P3[0] == P1[0]:
        print(0)
    elif P1[1] > P2[1]:
        if P3[0] > P1[0]:
            print(1)
        else:
            print(-1)
    else:
        if P3[0] > P1[0]:
            print(-1)
        else:
            print(1)
elif P1[1] == P2[1]:
    if P3[1] == P1[1]:
        print(0)
    elif P1[0] < P2[0]:
        if P3[1] > P1[1]:
            print(1)
        else:
            print(-1)
    else:
        if P3[1] > P1[1]:
            print(-1)
        else:
            print(1)
else:
    y_diff = P2[1] - P1[1]
    x_diff = P2[0] - P1[0]

    if y_diff * (P3[0] - P1[0]) > (P3[1] - P1[1]) * x_diff:
        print(-1)
    elif y_diff * (P3[0] - P1[0]) < (P3[1] - P1[1]) * x_diff:
        print(1)
    else:
        print(0)

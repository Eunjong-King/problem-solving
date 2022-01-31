import sys

T = int(sys.stdin.readline())

for _ in range(T):
    func = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    if n != 0:
        arr = list(map(int, sys.stdin.readline()[1:-2].split(',')))
    else:
        temp = sys.stdin.readline()
        arr = []

    i_from = 1
    i_to = len(arr) # i_from <= i <= i_to
    is_reverse = 1 # 1이 정방향

    for f in func:
        if f == 'R':
            is_reverse *= -1
        else:
            if is_reverse == 1:
                i_from += 1
            else:
                i_to -= 1

            if i_from - i_to == 2:
                print("error")
                break
    if i_from - i_to == 1:
        print('[]')
    elif i_from - i_to < 1:
        print('[', end='')
        if is_reverse == 1:
            for i in range(i_from-1, i_to):
                if i != (i_to-1):
                    print(arr[i], end=',')
                else:
                    print(arr[i], end='')
        else:
            for i in range(i_to-1, i_from-2, -1):
                if i != (i_from-1):
                    print(arr[i], end=',')
                else:
                    print(arr[i], end='')
        print(']')

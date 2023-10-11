from copy import deepcopy


def print_arr(arr):
    for i in range(len(arr)):
        for j in range(len(arr)):
            print('%2d' % (arr[i][j]), end=' ')
        print()
    print()


def calc_max(arr):
    my_max = 0

    for i in range(len(arr)):
        for j in range(len(arr)):
            my_max = max(my_max, arr[i][j])

    return my_max


def simu(arr, depth):
    if depth == 5:
        return calc_max(arr)

    my_max = 0

    for adder in range(4):
        new_arr = deepcopy(arr)
        is_add = [[False for _ in range(len(new_arr))] for _ in range(len(new_arr))]

        for i in range(1, len(new_arr)):
            for j in range(len(new_arr)):
                if adder == 0:
                    temp_i = j
                    temp_j = i
                    add_i = 0
                    add_j = -1
                elif adder == 1:
                    temp_i = i
                    temp_j = j
                    add_i = -1
                    add_j = 0
                elif adder == 2:
                    temp_i = j
                    temp_j = len(arr) - i - 1
                    add_i = 0
                    add_j = 1
                else:
                    temp_i = len(arr) - i - 1
                    temp_j = j
                    add_i = 1
                    add_j = 0

                new_i = temp_i + add_i
                new_j = temp_j + add_j

                while 0 <= new_i < len(new_arr) and 0 <= new_j < len(new_arr):
                    if new_arr[new_i][new_j] == 0:
                        new_arr[new_i][new_j] = new_arr[temp_i][temp_j]
                        new_arr[temp_i][temp_j] = 0
                        temp_i = new_i
                        temp_j = new_j
                    else:
                        if new_arr[new_i][new_j] == new_arr[temp_i][temp_j] and is_add[new_i][new_j] is False:
                            is_add[new_i][new_j] = True
                            new_arr[new_i][new_j] += new_arr[temp_i][temp_j]
                            new_arr[temp_i][temp_j] = 0
                        break

                    new_i = temp_i + add_i
                    new_j = temp_j + add_j

        my_max = max(simu(new_arr, depth + 1), my_max)

    return my_max


N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]

print(simu(arr, 0))

import sys


N = int(sys.stdin.readline().strip())
M = int(sys.stdin.readline().strip())
S = sys.stdin.readline().strip()
temp_S = 'I' + ('OI' * N)
temp = 0
count = 0
while True:
    ind = S[temp:].find(temp_S)
    if ind == -1:
        break
    ind += (temp + (N * 2) + 1)
    temp = ind
    temp_count = 0
    if ind+1 >= M:
        count += 1
        break
    while ind+1 < M:
        if S[ind] == 'O' and S[ind+1] == 'I':
            temp_count += 1
            ind += 2
        else:
            temp = ind
            break
    count += (1 + temp_count)

print(count)
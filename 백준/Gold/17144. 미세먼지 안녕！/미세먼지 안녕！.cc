#include <iostream>
#include <vector>

// 17144

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int R, C, T;
int air1 = -1, air2;
vvi v;
vector<pair<int, int>> directions{{-1, 0},
                                  {1,  0},
                                  {0,  -1},
                                  {0,  1}};

void diffusion() {
    vvi temp(R, vi(C, 0));
    temp[air1][0] = -1;
    temp[air2][0] = -1;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] > 0) {
                int count = 0;
                int cost = v[i][j] / 5;

                for (pair<int, int> direction: directions) {
                    int new_i = i + direction.first;
                    int new_j = j + direction.second;

                    if (0 <= new_i && new_i < R && 0 <= new_j && new_j < C && v[new_i][new_j] != -1) {
                        count++;

                        temp[new_i][new_j] += cost;
                    }
                }

                temp[i][j] += (v[i][j] - cost * count);
            }
        }
    }

    v = temp;
}

void circulation() {
    for (int i = air1 - 1; i > 0; i--) {
        v[i][0] = v[i - 1][0];
    }
    for (int i = air2 + 1; i < R - 1; i++) {
        v[i][0] = v[i + 1][0];
    }

    for (int j = 0; j < C - 1; j++) {
        v[0][j] = v[0][j + 1];
        v[R - 1][j] = v[R - 1][j + 1];
    }

    for (int i = 0; i < air1; i++) {
        v[i][C - 1] = v[i + 1][C - 1];
    }
    for (int i = R - 1; i > air2; i--) {
        v[i][C - 1] = v[i - 1][C - 1];
    }

    for (int j = C - 1; j > 1; j--) {
        v[air1][j] = v[air1][j - 1];
        v[air2][j] = v[air2][j - 1];
    }

    v[air1][1] = 0;
    v[air2][1] = 0;
}

int main() {
    cin >> R >> C >> T;

    v = vvi(R, vi(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> v[i][j];

            if (v[i][j] == -1) {
                if (air1 == -1) {
                    air1 = i;
                } else {
                    air2 = i;
                }
            }
        }
    }

    for (int i = 0; i < T; i++) {
        diffusion();
        circulation();

    }

    int result = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] > 0) {
                result += v[i][j];
            }
        }
    }
    cout << result << endl;

    return 0;
}
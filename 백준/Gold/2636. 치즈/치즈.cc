#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

using namespace std;
typedef vector<int> vi;

int N, M;
vector<pair<int, int>> adders{{-1, 0},
                              {1,  0},
                              {0,  -1},
                              {0,  1}};

int count_left(vector<vi> &v) {
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

void bfs(vector<vi> &v) {
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    isVisited[0][0] = true;

    queue<pair<bool, pair<int, int>>> q;
    q.push({false, {0, 0}});

    while (!q.empty()) {
        bool isFirst = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;

        for (auto adder: adders) {
            int new_i = i + adder.first;
            int new_j = j + adder.second;

            if (0 <= new_i && new_i < N && 0 <= new_j && new_j < M) {
                if (!isVisited[new_i][new_j]) {
                    isVisited[new_i][new_j] = true;

                    if (v[new_i][new_j] == 1) {
                        v[new_i][new_j] = 0;
                    } else {
                        q.push({isFirst, {new_i, new_j}});
                    }
                }
            }
        }

        q.pop();
    }
}

int main() {
    FAST_IO;

    cin >> N >> M;

    vector<vi> v(N, vi(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }

    int count = 0;
    int left = 0;
    int prev = 0;
    while (true) {
        prev = left;
        left = count_left(v);

        if (left == 0) {
            break;
        }

        bfs(v);

        count++;
    }

    cout << count << endl << prev << endl;

    return 0;
}
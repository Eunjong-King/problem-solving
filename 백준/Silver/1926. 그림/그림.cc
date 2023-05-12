#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int> vi;

vector<pair<int, int>> adders{{-1, 0},
                              {1,  0},
                              {0,  -1},
                              {0,  1}};

int N, M;

int dfs(vector<vi> &v, int x, int y) {
    stack<pair<int, int>> s;
    int size = 1;
    v[x][y] = 0;
    s.emplace(x, y);

    while (!s.empty()) {
        auto p = s.top();
        s.pop();

        int i = p.first;
        int j = p.second;
        for (auto adder: adders) {
            int new_x = i + adder.first;
            int new_y = j + adder.second;

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
                if (v[new_x][new_y] == 1) {
                    s.emplace(new_x, new_y);
                    v[new_x][new_y] = 0;
                    size++;
                }
            }
        }
    }

    return size;
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

    int max_size = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == 1) {
                int size = dfs(v, i, j);
                count++;
                max_size = max(max_size, size);
            }
        }
    }

    cout << count << '\n' << max_size << '\n';

    return 0;
}
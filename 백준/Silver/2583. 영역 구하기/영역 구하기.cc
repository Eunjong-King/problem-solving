#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef vector<bool> vb;

int N, M;
vector<pair<int, int>> adders{{0,  1},
                              {0,  -1},
                              {1,  0},
                              {-1, 0}};

void fill(vector<vb> &v, int x1, int y1, int x2, int y2) {
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            v[x][y] = true;
        }
    }
}

int bfs(vector<vb> &v, int x, int y) {
    int count = 0;

    queue<pair<int, int>> q;
    q.emplace(x, y);
    v[x][y] = true;

    while (!q.empty()) {
        count++;

        pair<int, int> p = q.front();
        q.pop();

        for (auto adder: adders) {
            int new_x = p.first + adder.first;
            int new_y = p.second + adder.second;

            if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && !v[new_x][new_y]) {
                q.emplace(new_x, new_y);
                v[new_x][new_y] = true;
            }
        }
    }

    return count;
}

int main() {
    FAST_IO;

    int K;
    cin >> N >> M >> K;

    vector<vb> v(M, vb(N, false));

    int x1, y1, x2, y2;
    for (int i = 0; i < K; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        fill(v, x1, y1, x2, y2);
    }

    vector<int> result;
    for (int x = 0; x < M; ++x) {
        for (int y = 0; y < N; ++y) {
            if (!v[x][y]) {
                result.push_back(bfs(v, x, y));
            }
        }
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int value: result) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
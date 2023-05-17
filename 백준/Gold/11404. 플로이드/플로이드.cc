#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef vector<int> vi;

constexpr int INF = 987654321;

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N + 1, vi(N + 1, INF));

    int from, to, cost;
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;

        if (arr[from][to] > cost) {
            arr[from][to] = cost;
        }
    }

    for (int through = 1; through <= N; ++through) {
        for (from = 1; from <= N; ++from) {
            for (to = 1; to <= N; ++to) {
                if (arr[from][through] != INF && arr[through][to] != INF) {
                    arr[from][to] = min(arr[from][to], arr[from][through] + arr[through][to]);
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (arr[i][j] == INF || i == j) cout << 0 << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
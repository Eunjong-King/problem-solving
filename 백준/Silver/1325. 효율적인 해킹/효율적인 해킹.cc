#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef vector<int> vi;

int visited[10001];
vector<int> m[10001];

int N, M;
int max_count = 0;
vi result;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int count = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int w = 0; w < m[top].size(); w++) {
            int nv = m[top][w];

            if (visited[nv] == 1) {
                continue;
            }

            visited[nv] = 1;
            count++;
            q.push(nv);
        }
    }

    result[start] = count;
    if (count > max_count) {
        max_count = count;
    }
}


int main() {
    FAST_IO;

    cin >> N >> M;
    result = vi(N + 1);

    int to, from;
    for (int i = 0; i < M; ++i) {
        cin >> to >> from;
        m[from].push_back(to);
    }

    for (int i = 1; i <= N; ++i) {
        memset(visited, 0, sizeof(int) * (N + 1));
        bfs(i);
    }

    for (int i = 1; i <= N; ++i) {
        if (result[i] == max_count) {
            cout << i << ' ';
        }
    }
    cout << '\n';


    return 0;
}
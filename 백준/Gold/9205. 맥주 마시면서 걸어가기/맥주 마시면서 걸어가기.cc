#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int con;

bool isFifty(pair<int, int> &p1, pair<int, int> &p2) {
    int distance = abs(p1.first - p2.first) + abs(p1.second - p2.second);

    return distance <= 1000;
}

bool bfs(vector<vector<int>> &graph) {
    int isVisited[con + 2];
    memset(isVisited, 0, sizeof(int) * (con + 2));
    queue<int> q;
    q.push(0);
    isVisited[0] = 1;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i: graph[t]) {
            if (isVisited[i] == 0) {
                if (i == con + 1) {
                    return true;
                }
                q.push(i);
                isVisited[i] = 1;
            }
        }
    }

    return false;
}

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        cin >> con;

        vector<pair<int, int>> v(con + 2);
        vector<vector<int>> graph(con + 2);
        for (int i = 0; i < con + 2; ++i) {
            cin >> v[i].first >> v[i].second;
        }

        for (int i = 0; i < con + 1; ++i) {
            for (int j = i + 1; j < con + 2; ++j) {
                if (isFifty(v[i], v[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        if (bfs(graph)) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
    return 0;
}
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;

constexpr int INF = 987654321;

vector<vector<pair<int, int>>> v;

void dijk(vector<int> &c, int start) {
    c[start] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(-0, start);

    while (!q.empty()) {
        pair<int, int> top = q.top();
        int cost = -top.first;
        int present = top.second;
        q.pop();

        if (c[present] < cost) continue;

        for (auto a: v[present]) {
            if (c[a.first] > c[present] + a.second) {
                c[a.first] = c[present] + a.second;
                q.emplace(-c[a.first], a.first);
            }
        }
    }
}

int main() {
    FAST_IO;

    int N, E;
    cin >> N >> E;

    v = vector<vector<pair<int, int>>>(N + 1);

    int v1, v2, c;
    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2 >> c;

        v[v1].emplace_back(v2, c);
        v[v2].emplace_back(v1, c);
    }

    vector<int> cost1(N + 1, INF);
    vector<int> cost2(N + 1, INF);
    vector<int> cost3(N + 1, INF);

    cin >> v1 >> v2;
    dijk(cost1, 1);
    dijk(cost2, v1);
    dijk(cost3, v2);
    // route1, route2 둘다 안되거나 v1 v2 연결이 안됨
    if ((!(cost1[v1] != INF && cost3[N] != INF) && !(cost1[v2] != INF && cost2[N] != INF)) || cost2[v2] == INF) {
        cout << -1 << '\n';
    } else {
        cout << min(cost1[v1] + cost3[N], cost1[v2] + cost2[N]) + cost2[v2] << '\n';
    }

    return 0;
}
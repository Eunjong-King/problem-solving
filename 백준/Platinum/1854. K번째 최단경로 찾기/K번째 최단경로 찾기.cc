#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;

int N, M, K;
map<int, vpii> m;
vector<priority_queue<int>> result;

void dijkstra(int start) {
    priority_queue<pii> pq;
    pq.emplace(0, start);

    result = vector<priority_queue<int>>(N + 1);
    result[start].push(0);

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        for (pii p: m[now_node]) {
            int next_node = p.first;
            int next_cost = p.second + now_cost;

            if (result[next_node].size() < K) {
                result[next_node].push(next_cost);
                pq.emplace(-next_cost, next_node);
            } else {
                if (result[next_node].top() > next_cost) {
                    result[next_node].pop();
                    result[next_node].push(next_cost);
                    pq.emplace(-next_cost, next_node);
                }
            }
        }
    }
}

int main() {
    FAST_IO;

    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        m[A].emplace_back(B, C);
    }

    dijkstra(1);

    for (int i = 1; i <= N; ++i) {
        if (result[i].size() < K) {
            cout << -1 << endl;
        } else {
            cout << result[i].top() << endl;
        }
    }

    return 0;
}
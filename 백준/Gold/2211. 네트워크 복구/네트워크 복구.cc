#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vb> vvb;

int N, M;
map<int, vpii> m;
vi result;

void dijkstra(int start) {
    priority_queue<pii> pq;
    pq.emplace(0, start);

    vi distances(N + 1, 1e9);
    distances[start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[now_node] < now_cost) {
            continue;
        }

        for (pii p: m[now_node]) {
            int next_node = p.first;
            int next_cost = p.second + now_cost;

            if (distances[next_node] > next_cost) {
                result[next_node] = now_node;

                distances[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }
}

int main() {
    FAST_IO;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        m[A].emplace_back(B, C);
        m[B].emplace_back(A, C);
    }

    result = vi(N + 1, 0);
    dijkstra(1);

    cout << N - 1 << endl;
    for (int i = 2; i <= N; ++i) {
        cout << result[i] << ' ' << i << endl;
    }

    return 0;
}
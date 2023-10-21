#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define pb push_back

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
vvi whitelist;
vpii candidate;

int dijkstra() {
    priority_queue<pii> pq;
    pq.push({0, 1});

    vi distances(N + 1, 1e9);
    distances[1] = 0;

    whitelist = vvi(N + 1, vi(N + 1, 0));

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[now_node] < now_cost) {
            continue;
        }

        for (pii p: m[now_node]) {
            int next_cost = now_cost + p.second;
            int next_node = p.first;

            if (distances[next_node] > next_cost) {
                whitelist[next_node] = vi(N + 1, false);
                whitelist[next_node][now_node] = true;

                distances[next_node] = next_cost;
                pq.push({-next_cost, next_node});
            }
        }
    }

    int to = N;
    while (to != 1) {
        for (int i = 1; i <= N; ++i) {
            if (whitelist[to][i]) {
                candidate.pb({i, to});
                to = i;
                break;
            }
        }
    }

    return distances[N];
}

int ban_dijkstra(pii ban) {
    priority_queue<pii> pq;
    pq.push({0, 1});

    vi distances(N + 1, 1e9);
    distances[1] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[now_node] < now_cost) {
            continue;
        }

        for (pii p: m[now_node]) {
            int next_cost = now_cost + p.second;
            int next_node = p.first;

            if ((ban.first == now_node && ban.second == next_node) ||
                (ban.second == now_node && ban.first == next_node)) {
                continue;
            }

            if (distances[next_node] > next_cost) {
                distances[next_node] = next_cost;
                if (next_node != N) {
                    pq.push({-next_cost, next_node});
                }
            }
        }
    }

    return distances[N];
}

int main() {
    FAST_IO;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int A, B, T;
        cin >> A >> B >> T;

        m[A].pb({B, T});
        m[B].pb({A, T});
    }

    int shortest = dijkstra();
    
    int result = 0;
    for (pii p: candidate) {
        int ret = ban_dijkstra(p);

        result = max(result, ret);
    }

    if (result == 1e9) {
        cout << -1 << endl;
    } else {
        cout << result - shortest << endl;
    }


    return 0;
}
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

int N, M, K;
map<int, vpii> m;
vector<vector<ll>> dp;

void dijkstra() {
    dp = vector<vector<ll>>(K + 1, vector<ll>(N + 1, 20000000000));
    dp[K][1] = 0;

    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {K, 1}});

    vvb visited(K + 1, vb(N + 1, false));

    while (!pq.empty()) {
        ll now_cost = -pq.top().first;
        int now_left = pq.top().second.first;
        int now_node = pq.top().second.second;

        pq.pop();

        if (!visited[now_left][now_node]) {
            visited[now_left][now_node] = true;

            for (pii p: m[now_node]) {
                int next_node = p.first;
                ll next_cost = now_cost + p.second;

                if (!visited[now_left][next_node] && dp[now_left][next_node] > next_cost) {
                    dp[now_left][next_node] = next_cost;
                    pq.push({-next_cost, {now_left, next_node}});
                }

                if (now_left > 0) {
                    if (!visited[now_left - 1][next_node] && dp[now_left - 1][next_node] > now_cost) {
                        dp[now_left - 1][next_node] = now_cost;
                        pq.push({-now_cost, {now_left - 1, next_node}});
                    }
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

        m[A].pb({B, C});
        m[B].pb({A, C});
    }

    dijkstra();

    ll result = 20000000000;
    for (int i = 0; i <= K; ++i) {
        result = min(result, dp[i][N]);
    }

    cout << result << endl;

    return 0;
}
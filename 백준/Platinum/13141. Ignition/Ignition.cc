#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

/* DEFINES	*/
#define FAST_IO                       \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
#define f first
#define s second
#define sp << " " <<
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; ++i)
#define inrange(i, a, b) (a <= i && i < b)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define printv(a)                          \
    {                                      \
        for (auto u : a) cout << u << " "; \
        cout << endl;                      \
    }
#define printm(a)                                    \
    {                                                \
        for (auto u : a) cout << u.f sp u.s << endl; \
    }
#define pb push_back
#define eb emplace_back
#define mp make_pair

/* TYPEDEFS	*/
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

/* CONSTANTS */
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const long double EPS = 1e-9;

int main() {
    FAST_IO

    int N, M;
    cin >> N >> M;

    vvi dist(N + 1, vi(N + 1, INF));
    vector<pair<int, pii>> edges(M);

    int f, t, c;
    forn(i, M) {
        cin >> f >> t >> c;

        edges[i] = {c, {f, t}};

        dist[f][t] = min(c, dist[f][t]);
        dist[t][f] = min(c, dist[t][f]);
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int mid = 1; mid <= N; mid++) {
        for (int from = 1; from <= N; from++) {
            for (int to = 1; to <= N; to++) {
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
            }
        }
    }

    // for (int from = 1; from <= N; from++) {
    //     for (int to = 1; to <= N; to++) {
    //         cout << dist[from][to] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    double answer = 300000.0;
    for (int start = 1; start <= N; start++) {
        double temp_result = 0;

        trav(edge, edges) {
            int cost = edge.f;
            int node1 = edge.s.f;
            int node2 = edge.s.s;

            int node1_cost = dist[start][node1];
            int node2_cost = dist[start][node2];

            if (node1_cost > node2_cost) {
                swap(node1_cost, node2_cost);
            }

            double edge_time;
            if (node1_cost + cost < node2_cost) {
                edge_time = (double)(node1_cost + cost);
                temp_result = max(temp_result, edge_time);
            } else {
                int t = cost - (node2_cost - node1_cost);
                edge_time = ((double)t / 2) + (double)node2_cost;
                temp_result = max(temp_result, edge_time);
            }
            // cout << node1 << " " << node2 << " -> " << edge_time << endl;
        }
        // cout << start << "에서 시작 : " << temp_result << endl;

        answer = min(answer, temp_result);
    }

    cout << fixed;
    cout.precision(1);
    cout << answer << endl;

    // for (int from = 1; from <= N; from++) {
    //     for (int to = 1; to <= N; to++) {
    //         cout << dist[from][to] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}
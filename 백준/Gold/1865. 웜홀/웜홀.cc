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
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x, y) memset(x, y, sizeof(x))
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i > b; --i)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

/* TYPEDEFS	*/
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

/* CONSTANTS */
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

int main() {
    FAST_IO

    int T;
    cin >> T;

    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<pair<int, pii>> v;
        int from, to, cost;
        for (int i = 0; i < M; i++) {
            cin >> from >> to >> cost;
            v.push_back({cost, {from, to}});
            v.push_back({cost, {to, from}});
        }
        for (int i = 0; i < W; i++) {
            cin >> from >> to >> cost;
            v.push_back({-cost, {from, to}});
        }

        vi distance(N + 1, INF);
        distance[1] = 0;

        for (int i = 1; i < N; i++) {
            trav(a, v) {
                int cost = a.fi;
                int from = a.se.fi;
                int to = a.se.se;

                if (distance[to] > distance[from] + cost) {
                    distance[to] = distance[from] + cost;
                }
            }
        }

        bool is_negative_cycle = false;
        trav(a, v) {
            int cost = a.fi;
            int from = a.se.fi;
            int to = a.se.se;

            if (distance[to] > distance[from] + cost) {
                is_negative_cycle = true;
                break;
            }
        }

        if (is_negative_cycle) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
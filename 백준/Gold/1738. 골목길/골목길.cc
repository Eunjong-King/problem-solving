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
#define eb emplace_back
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

bool isWithEnd(const vector<vpii>& v, int now, int End) {
    stack<int> s;
    s.push(now);

    bool is_visited[101] = {0};
    is_visited[now] = true;

    while (!s.empty()) {
        now = s.top();
        s.pop();

        for (auto a : v[now]) {
            int next = a.fi;

            if (!is_visited[next]) {
                if (next == End) {
                    return true;
                }

                is_visited[next] = true;

                s.push(now);
                s.push(next);

                break;
            }
        }
    }

    return false;
}

int main() {
    FAST_IO

    int N, M;
    cin >> N >> M;

    vector<vpii> v(N + 1);
    int from, to, cost;
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;

        v[from].pb(mp(to, -cost));
    }

    vi distance(N + 1, INF);
    distance[1] = 0;

    vi origin(N + 1, -1);

    bool hasNegCircle = false;
    for (int i = 1; i <= N; i++) {
        for (int from = 1; from <= N; from++) {
            for (auto a : v[from]) {
                int to = a.fi;
                int cost = a.se;

                if (distance[from] == INF) {
                    continue;
                }

                if (distance[to] > distance[from] + cost) {
                    distance[to] = distance[from] + cost;
                    origin[to] = from;

                    if (i == N && isWithEnd(v, to, N)) {
                        hasNegCircle = true;
                    }
                }
            }
        }
    }

    if (distance[N] == INF || hasNegCircle) {
        cout << -1 << endl;
    } else {
        vi result;
        result.pb(N);

        int from = origin[N];
        result.pb(from);

        while (from != 1) {
            from = origin[from];

            result.pb(from);
        }

        reverse(all(result));

        for (auto a : result) {
            cout << a << ' ';
        }
        cout << endl;
    }

    return 0;
}
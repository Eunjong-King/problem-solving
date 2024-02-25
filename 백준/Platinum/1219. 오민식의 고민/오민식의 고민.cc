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

vector<vpii> v(200);

bool isRealCircle(int start, int E) {
    bool visited[200] = {0};
    visited[start] = true;

    if (start == E) {
        return true;
    }

    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int now = s.top();
        s.pop();

        for (auto a : v[now]) {
            int next = a.fi;

            if (!visited[next]) {
                if (next == E) {
                    return true;
                }

                visited[next] = true;

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

    int N, S, E, M;
    cin >> N >> S >> E >> M;

    int from, to, cost;
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;

        v[from].push_back({to, cost});
    }

    vi earns(N);
    for (int i = 0; i < N; i++) {
        cin >> earns[i];
    }

    bool isNegCircle = false;
    vll dist(N, LLINF);
    dist[S] = -(ll)earns[S];

    for (int i = 1; i <= N; i++) {
        for (int from = 0; from < N; from++) {
            for (auto a : v[from]) {
                int to = a.fi;
                int cost = a.se - earns[to];

                if (dist[from] == LLINF) {
                    continue;
                }

                if (dist[to] > dist[from] + (ll)cost) {
                    dist[to] = dist[from] + (ll)cost;

                    if (i == N && isRealCircle(to, E)) {
                        isNegCircle = true;

                        cout << "Gee" << endl;

                        return 0;
                    }
                }
            }
        }
    }

    if (dist[E] == LLINF) {
        cout << "gg" << endl;

        return 0;
    }

    cout << -dist[E] << endl;

    return 0;
}
#include <bits/stdc++.h>

#define FAST_IO                       \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int N, M;
vvi v(101, vi(101, 0));
vector<pii> adders{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool air_bfs() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vvi airs(N, vi(M, 0));

    queue<pii> q;
    q.push(mp(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        for (auto adder : adders) {
            int new_x = x + adder.fi;
            int new_y = y + adder.se;

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
                if (v[new_x][new_y] == 1) {
                    airs[new_x][new_y]++;
                    continue;
                }

                if (!visited[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    q.push(mp(new_x, new_y));
                }
            }
        }
    }

    bool isEnd = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (airs[i][j] >= 2) {
                isEnd = false;
                v[i][j] = 0;
            }
        }
    }

    return isEnd;
}

int main() {
    FAST_IO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    int count = 0;
    while (true) {
        if (air_bfs()) {
            break;
        }

        count++;
    }

    cout << count << endl;

    return 0;
}
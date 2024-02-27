#include <iostream>
#include <vector>
using namespace std;

/* DEFINES	*/
#define FAST_IO                       \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
#define f first
#define s second
#define fill(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; ++i)
#define inrange(i, a, b) (a <= i && i < b)
#define trav(a, x) for (auto& a : x)
#define pb push_back
#define mp make_pair

/* TYPEDEFS	*/
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

/* CONSTANTS */
const ll INF = 1e9;

vector<vector<pair<int, pair<short, short>>>> ghost_hole;
vector<pair<short, short>> adders{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void input(bool isGrave[][30], bool isWarp[][30], const short& H, const short& W) {
    short G;
    cin >> G;

    short x1, y1, x2, y2;
    int cost;

    forn(i, G) {
        cin >> x1 >> y1;

        isGrave[x1][y1] = true;
    }

    short E;
    cin >> E;

    forn(i, E) {
        cin >> x1 >> y1 >> x2 >> y2 >> cost;

        isWarp[x1][y1] = true;

        ghost_hole[x1][y1] = {cost, {x2, y2}};
    }
}

int main() {
    FAST_IO

    while (true) {
        short H, W;
        cin >> H >> W;

        if (H == 0) {
            break;
        }

        ghost_hole = vector<vector<pair<int, pair<short, short>>>>(H, vector<pair<int, pair<short, short>>>(W));

        bool isGrave[30][30] = {0};
        bool isWarp[30][30] = {0};

        input(isGrave, isWarp, H, W);

        vvi dist(H, vi(W, INF));
        dist[0][0] = 0;

        bool is_neg_circle = false;

        for (short i = 1; i <= W * H; i++) {
            for (short x = 0; x < H; x++) {
                for (short y = 0; y < W; y++) {
                    if (isGrave[x][y] || (x == H - 1 && y == W - 1) || dist[x][y] == INF) continue;

                    if (isWarp[x][y]) {
                        short new_x = ghost_hole[x][y].s.f;
                        short new_y = ghost_hole[x][y].s.s;
                        int cost = ghost_hole[x][y].f;

                        if (dist[new_x][new_y] > dist[x][y] + cost) {
                            dist[new_x][new_y] = dist[x][y] + cost;

                            if (i == W * H) {
                                is_neg_circle = true;
                            }
                        }

                        continue;
                    }

                    trav(adder, adders) {
                        short new_x = x + adder.f;
                        short new_y = y + adder.s;
                        int cost = 1;

                        if (!inrange(new_x, 0, H) || !inrange(new_y, 0, W)) {
                            continue;
                        }

                        if (isGrave[new_x][new_y]) continue;

                        if (dist[new_x][new_y] > dist[x][y] + cost) {
                            dist[new_x][new_y] = dist[x][y] + cost;

                            if (i == W * H) {
                                is_neg_circle = true;
                            }
                        }
                    }
                }
            }
        }

        if (is_neg_circle) {
            cout << "Never" << endl;
        } else if (dist[H - 1][W - 1] == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[H - 1][W - 1] << endl;
        }
    }

    return 0;
}
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
typedef vector<vector<char>> vvc;

struct Data {
    int x;
    int y;
    int direction;
    int cost;

    Data(int tx, int ty, int td, int tc) {
        x = tx;
        y = ty;
        direction = td;
        cost = tc;
    }
};

int W, H, X1 = -1, Y1, X2, Y2;
vvc v;
vvi costs;
vpii directions{{1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}};
int arr[100][100][4];

void bfs() {
    queue<Data> q;
    q.emplace(X1, Y1, -1, 0);

    costs = vvi(H, vi(W, 1e9));
    costs[X1][Y1] = 0;

    while (!q.empty()) {
        int now_cost = q.front().cost;
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_direction = q.front().direction;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = now_x + directions[i].first;
            int new_y = now_y + directions[i].second;
            int new_direction = i;
            int new_cost = now_cost;

            if (now_direction != -1 && now_direction != new_direction) {
                new_cost++;
            }

            if (0 <= new_x && new_x < H && 0 <= new_y && new_y < W && v[new_x][new_y] != '*') {
                if (costs[new_x][new_y] >= new_cost && arr[new_x][new_y][new_direction] > new_cost) {
                    arr[new_x][new_y][new_direction] = new_cost;
                    costs[new_x][new_y] = new_cost;
                    if (new_x == X2 && new_y == Y2) {
                        continue;
                    }
                    q.emplace(new_x, new_y, new_direction, new_cost);
                }
            }
        }
    }
}

int main() {
    FAST_IO;

    cin >> W >> H;

    v = vvc(H, vector<char>(W));
    for (int i = 0; i < H; ++i) {
        string inp;
        cin >> inp;
        for (int j = 0; j < W; ++j) {
            v[i][j] = inp[j];

            if (X1 == -1 && inp[j] == 'C') {
                X1 = i, Y1 = j;
            } else if (inp[j] == 'C') {
                X2 = i, Y2 = j;
            }
        }
    }

    for (auto &i: arr) {
        for (auto &j: i) {
            for (int &k: j)
                k = 1e9;
        }
    }

    bfs();

    cout << costs[X2][Y2] << endl;

    return 0;
}
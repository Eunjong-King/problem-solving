#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;

int X1 = -1, Y1, X2, Y2;
int H, W;
vvc v;
vpii directions{{-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}};

int doors[103][103][3];

void bfs(int x, int y, int idx) {
    priority_queue<pair<int, pii>> q;
    q.push({0, {x, y}});

    doors[x][y][idx] = 0;

    while (!q.empty()) {
        int now_door = -q.top().first;
        int now_x = q.top().second.first;
        int now_y = q.top().second.second;

        q.pop();

        for (pii direction: directions) {
            int new_x = now_x + direction.first;
            int new_y = now_y + direction.second;
            int new_door = now_door;

            if (0 <= new_x && new_x < H + 2 && 0 <= new_y && new_y < W + 2) {
                if (v[new_x][new_y] == '*') {
                    continue;
                } else if (v[new_x][new_y] == '#') {
                    new_door++;
                }

                if (doors[new_x][new_y][idx] > new_door) {
                    doors[new_x][new_y][idx] = new_door;
                    q.push({-new_door, {new_x, new_y}});
                }
            }
        }
    }
}

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        X1 = -1;

        cin >> H >> W;

        v = vvc(H + 2, vc(W + 2, '.'));

        for (int i = 1; i <= H; ++i) {
            string inp;
            cin >> inp;

            for (int j = 1; j <= W; ++j) {
                v[i][j] = inp[j - 1];

                if (X1 == -1 && inp[j - 1] == '$') {
                    X1 = i, Y1 = j;
                } else if (inp[j - 1] == '$') {
                    X2 = i, Y2 = j;
                }
            }
        }

        for (int k = 0; k < 3; ++k) {
            for (int i = 0; i < H + 2; ++i) {
                for (int j = 0; j < W + 2; ++j) {
                    doors[i][j][k] = 20000;
                }
            }
        }

        bfs(0, 0, 0);
        bfs(X1, Y1, 1);
        bfs(X2, Y2, 2);

        int answer = 20000;
        for (int i = 0; i < H + 2; ++i) {
            for (int j = 0; j < W + 2; ++j) {
                if (v[i][j] == '*') {
                    continue;
                }

                if (doors[i][j][0] == -1 || doors[i][j][1] == -1 || doors[i][j][2] == -1) {
                    continue;
                }

                int door_sum = doors[i][j][0] + doors[i][j][1] + doors[i][j][2];

                if (v[i][j] == '#') {
                    door_sum -= 2;
                }
                
                answer = min(answer, door_sum);
            }
        }

        cout << answer << endl;
    }

    return 0;
}
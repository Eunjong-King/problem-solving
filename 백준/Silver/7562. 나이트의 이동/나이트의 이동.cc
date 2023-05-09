#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef vector<int> vi;

vector<pair<int, int>> adder{{-2, 1},
                             {2,  -1},
                             {-2, -1},
                             {2,  1},
                             {-1, 2},
                             {1,  -2},
                             {-1, -2},
                             {1,  2}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, I;

    cin >> T;

    while (T--) {
        cin >> I;

        vector<vector<bool>> mask(I, vector<bool>(I, false));
        queue<tuple<int, int, int>> q;

        pair<int, int> from;
        pair<int, int> to;

        cin >> from.first >> from.second;
        cin >> to.first >> to.second;

        q.emplace(from.first, from.second, 0);

        while (!q.empty()) {
            tuple<int, int, int> front = q.front();
            q.pop();

            int x = get<0>(front);
            int y = get<1>(front);

            if (to.first == x && to.second == y) {
                cout << get<2>(front) << '\n';
                break;
            }

            if (mask[x][y]) {
                continue;
            }
            mask[x][y] = true;

            for (auto p: adder) {
                int new_x = x + p.first;
                int new_y = y + p.second;

                if (new_x >= 0 && new_x < I && new_y >= 0 && new_y < I) {
                    q.emplace(new_x, new_y, get<2>(front) + 1);
                }
            }
        }
    }

    return 0;
}
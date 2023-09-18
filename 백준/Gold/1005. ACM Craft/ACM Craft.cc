#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> vi;

vi topo(1002);
vi building;
vi costs(1002);

int main() {
    FAST_IO;
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        for (int i = 0; i <= N; ++i) {
            topo[i] = 0;
        }

        building = vi(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> building[i];
            costs[i] = building[i];
        }

        int a, b;
        map<int, vector<int>> m;
        for (int i = 0; i < K; ++i) {
            cin >> a >> b;

            topo[b]++;
            m[a].push_back(b);
        }

        int dest;
        cin >> dest;

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (topo[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int f = q.front();

            for (auto a: m[f]) {
                topo[a]--;

                costs[a] = max(costs[a], costs[f] + building[a]);

                if (topo[a] == 0) {
                    q.push(a);
                }
            }
            q.pop();
        }
        cout << costs[dest] << '\n';
    }

    return 0;
}
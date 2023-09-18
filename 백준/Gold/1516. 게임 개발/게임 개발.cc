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

    int N;
    cin >> N;

    building = vi(N + 1);

    map<int, vector<int>> m;
    for (int i = 1; i <= N; ++i) {
        cin >> building[i];
        costs[i] = building[i];

        int inp;
        while (true) {
            cin >> inp;

            if (inp == -1) {
                break;
            }

            topo[i]++;
            m[inp].push_back(i);
        }
    }

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

    for (int i = 1; i <= N; ++i) {
        cout << costs[i] << '\n';
    }

    return 0;
}
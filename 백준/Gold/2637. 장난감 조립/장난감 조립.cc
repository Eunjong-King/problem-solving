#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef vector<int> vi;

int topo[102];
int result[102];
bool isNotBase[102];

int main() {
    FAST_IO;

    int N, M;

    cin >> N >> M;

//    for (int i = 1; i <= N; ++i) {
//        result[i] = 1;
//    }

    int x, y, k;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> k;

        isNotBase[x] = true;
        m[x].emplace_back(y, k);
        topo[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (topo[i] == 0) {
            q.push(i);
            result[i] = 1;
        }
    }

    while (!q.empty()) {
        int f = q.front();

        for (auto p: m[f]) {
            int i = p.first;
            int cost = p.second;

            result[i] += cost * result[f];
            topo[i]--;

            if (topo[i] == 0) {
                q.push(i);
            }
        }

        q.pop();
    }

    for (int i = 1; i <= N; ++i) {
        if (!isNotBase[i]) {
            cout << i << ' ' << result[i] << '\n';
        }
    }

    return 0;
}
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> vi;

int topo[1002];
pair<int, int> sdata[1002];
int strahler[1002];

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        int K, M, P;
        cin >> K >> M >> P;

        for (int i = 1; i <= M; ++i) {
            topo[i] = 0;
            sdata[i] = {0, 0};
            strahler[i] = 0;
        }

        map<int, vi> m;
        int a, b;
        for (int i = 0; i < P; ++i) {
            cin >> a >> b;

            topo[b]++;
            m[a].push_back(b);
        }

        queue<int> q;
        for (int i = 1; i <= M; ++i) {
            if (topo[i] == 0) {
                q.push(i);
                sdata[i].first = 1;
            }
        }

        while (!q.empty()) {
            int f = q.front();

            if (sdata[f].second >= 2) {
                strahler[f] = sdata[f].first + 1;
            } else {
                strahler[f] = sdata[f].first;
            }

            for (int i: m[f]) {
                topo[i]--;

                if (sdata[i].first == strahler[f]) {
                    sdata[i].second++;
                } else if (sdata[i].first < strahler[f]) {
                    sdata[i] = {strahler[f], 1};
                }

                if (topo[i] == 0) {
                    q.push(i);
                }
            }

            q.pop();
        }

        cout << K << ' ' << strahler[M] << endl;
    }

    return 0;
}
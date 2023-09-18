#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> vi;

vi topo(32002);

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    int a, b;
    map<int, vector<int>> m;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        topo[b]++;
        m[a].push_back(b);
    }

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (topo[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int f = q.front();
        cout << f << ' ';
        for (auto a: m[f]) {
            topo[a]--;

            if (topo[a] == 0) {
                q.push(a);
            }
        }
        q.pop();
    }
    cout << '\n';

    return 0;
}
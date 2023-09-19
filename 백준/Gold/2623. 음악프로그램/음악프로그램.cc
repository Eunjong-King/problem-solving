#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;

vi topo(1002);

int main() {
    int N, M;
    cin >> N >> M;

    map<int, vi> m;
    int t, prev = -1, now;
    for (int i = 0; i < M; i++) {
        prev = -1;
        cin >> t;

        while (t--) {
            cin >> now;

            if (prev != -1) {
                m[prev].push_back(now);
                topo[now]++;
            }

            prev = now;
        }
    }

    queue<int> pq;
    for (int i = 1; i <= N; i++) {
        if (topo[i] == 0) {
            pq.push(i);
        }
    }

    vi answer;
    while (!pq.empty()) {
        int front = pq.front();

        answer.push_back(front);

        for (int i: m[front]) {
            topo[i]--;

            if (topo[i] == 0) {
                pq.push(i);
            }
        }

        pq.pop();
    }

    if (answer.size() == N) {
        for (auto a: answer) {
            cout << a << '\n';
        }
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
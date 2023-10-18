#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;

vi nominee;
vvi distances;
map<int, vpii> m;
int N, M, T, S, G, H;

void dijkstra(int start) {
    priority_queue<pii> pq;
    pq.emplace(0, start);

    distances[start][start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[start][now_node] < now_cost) {
            continue;
        }

        for (pii p: m[now_node]) {
            int next_cost = p.second + now_cost;
            int next_node = p.first;

            if (distances[start][next_node] > next_cost) {
                distances[start][next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M >> T;
        cin >> S >> G >> H;

        m = map<int, vpii>();
        for (int i = 0; i < M; ++i) {
            int A, B, D;
            cin >> A >> B >> D;

            m[A].emplace_back(B, D);
            m[B].emplace_back(A, D);
        }

        nominee = vi(T);
        for (int i = 0; i < T; ++i) {
            cin >> nominee[i];
        }

        distances = vvi(N + 1, vi(N + 1, 100000000));

        dijkstra(S);
        dijkstra(G);
        dijkstra(H);

        vi answer;
        for (int i: nominee) {
            if (distances[S][i] == distances[S][G] + distances[G][H] + distances[H][i] ||
                distances[S][i] == distances[S][H] + distances[H][G] + distances[G][i]) {
                answer.push_back(i);
            }
        }
        sort(answer.begin(), answer.end());

        for (int i: answer) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
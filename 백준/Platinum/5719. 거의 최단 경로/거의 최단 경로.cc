#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int N, M;
map<int, vector<pair<int, int>>> m;
vvb pre_blacklist;
vvb blacklist;

void pre_dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);

    vi distances(N, 1e9);
    distances[start] = 0;

    pre_blacklist = vvb(N, vector<bool>(N, false));

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[now_node] < now_cost) {
            continue;
        }

        for (pair<int, int> p: m[now_node]) {
            int next_cost = p.second + now_cost;
            int next_node = p.first;

            if (distances[next_node] > next_cost) {
                for (int i = 0; i < N; ++i) {
                    pre_blacklist[i][next_node] = false;
                }
                pre_blacklist[now_node][next_node] = true;

                distances[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            } else if (distances[next_node] == next_cost) {
                pre_blacklist[now_node][next_node] = true;
            }
        }
    }
}

void make_blacklist(int start, int end) {
    if (start == end) {
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (pre_blacklist[i][end]) {
            blacklist[i][end] = true;
            pre_blacklist[i][end] = false;

            make_blacklist(start, i);
        }
    }
}

int dijkstra(int start, int end) {
    priority_queue<pii> pq;
    pq.emplace(0, start);

    vi distances(N, 1e9);
    distances[start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;

        pq.pop();

        if (distances[now_node] < now_cost) {
            continue;
        }

        for (pii p: m[now_node]) {
            int next_node = p.first;
            int next_cost = p.second + now_cost;

            if (blacklist[now_node][next_node]) {
                continue;
            }

            if (distances[next_node] > next_cost) {
                distances[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }

    return distances[end];
}

int main() {
    FAST_IO;

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        int S, D;
        cin >> S >> D;

        m = map<int, vector<pair<int, int>>>();
        for (int i = 0; i < M; ++i) {
            int U, V, P;
            cin >> U >> V >> P;

            m[U].emplace_back(V, P);
        }

        pre_dijkstra(S);

        blacklist = vvb(N, vector<bool>(N, false));
        make_blacklist(S, D);

        int result = dijkstra(S, D);

        if (result == 1e9) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
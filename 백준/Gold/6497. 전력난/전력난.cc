#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(200001);

int find_parent(int a) {
    if (a == parent[a]) {
        return a;
    }

    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    int aref = find_parent(a);
    int bref = find_parent(b);

    parent[aref] = bref;
}

int main() {
    FAST_IO;

    int N, M;
    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> edges(M);
        int a, b, cost, total_cost = 0;
        for (int i = 0; i < M; ++i) {
            cin >> a >> b >> cost;

            total_cost += cost;
            edges[i] = {cost, {a, b}};
        }

        sort(edges.begin(), edges.end());

        int result = 0;
        for (auto edge: edges) {
            a = edge.second.first;
            b = edge.second.second;

            if (find_parent(a) != find_parent(b)) {
                union_parent(a, b);
                result += edge.first;
            }
        }

        cout << total_cost - result << '\n';
    }

    return 0;
}
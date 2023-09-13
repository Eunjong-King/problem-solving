#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(1001);

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

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges((N * N - N) / 2);
    int idx = 0, cost;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost;

            if (i <= j) {
                continue;
            }

            edges[idx++] = {cost, {i, j}};
        }
    }

    sort(edges.begin(), edges.end());

    int a, b;
    long long result = 0;
    for (auto edge: edges) {
        a = edge.second.first;
        b = edge.second.second;

        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            result += edge.first;
        }
    }
    cout << result << '\n';

    return 0;
}
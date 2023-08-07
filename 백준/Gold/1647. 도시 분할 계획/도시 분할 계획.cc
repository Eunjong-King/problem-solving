#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

int find_parent(int a) {
    if(a == parent[a]) {
        return a;
    }

    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    parent[b] = a;
}

bool is_same_parent(int a, int b) {
    return find_parent(a) == find_parent(b);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> v(M);

    int v1, v2, cost;
    for(int i=0; i<M; i++) {
        cin >> v1 >> v2 >> cost;

        v[i] = {cost, {v1, v2}};
    }

    sort(v.begin(), v.end());

    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }

    int total = 0;
    int max_cost = 0;
    for(auto a : v) {
        if(is_same_parent(a.second.first, a.second.second)) {
            continue;
        }

        total += a.first;
        max_cost = a.first > max_cost ? a.first : max_cost;

        union_parent(a.second.first, a.second.second);
    }

    cout << total - max_cost << endl;

    return 0;
}
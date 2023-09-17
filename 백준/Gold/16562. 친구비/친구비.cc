#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;

vi parent(10002);
vi costs(10002);

int find_parent(int a) {
    if (a == parent[a]) {
        return a;
    }

    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    int arep = find_parent(a);
    int brep = find_parent(b);

    parent[arep] = brep;
}

int main() {
    FAST_IO;

    int N, M, k;
    cin >> N >> M >> k;

    int cost;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;

        cin >> cost;
        costs[i] = cost;
    }

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        union_parent(a, b);
    }

    map<int, int> min_cost;
    for (int i = 1; i <= N; ++i) {
        int p = find_parent(i);

        if (min_cost[p] == 0) {
            min_cost[p] = costs[i];
        } else {
            min_cost[p] = min(min_cost[p], costs[i]);
        }
    }

    int result = 0;
    for (auto m: min_cost) {
        result += m.second;
    }

    if (result > k) {
        cout << "Oh no" << '\n';
    } else {
        cout << result << '\n';
    }

    return 0;
}
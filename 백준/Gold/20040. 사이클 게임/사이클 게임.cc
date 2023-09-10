#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(500002);

int find_parent(int i) {
    if (i == parent[i]) {
        return i;
    }

    return parent[i] = find_parent(parent[i]);
}

void union_parent(int i, int j) {
    int irep = find_parent(i);
    int jrep = find_parent(j);

    parent[irep] = jrep;
}

bool is_cycle(int i, int j) {
    int irep = find_parent(i);
    int jrep = find_parent(j);

    return irep == jrep;
}

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int a, b;
    int answer = 0;
    for (int i = 1; i <= M; ++i) {
        cin >> a >> b;

        if (is_cycle(a, b) && answer == 0) {
            answer = i;
        }
        union_parent(a, b);
    }

    cout << answer << '\n';

    return 0;
}
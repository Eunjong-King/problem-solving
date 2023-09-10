#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(202);

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

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    vector<vi> data(N + 1, vi(N + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> data[i][j];
        }
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (data[i][j] == 1) {
                union_parent(i, j);
            }
        }
    }

    int inp, base;
    bool isOkay = true;
    for (int i = 0; i < M; ++i) {
        cin >> inp;

        if (i == 0) {
            base = find_parent(inp);
            continue;
        }

        if (find_parent(inp) != base) {
            isOkay = false;
            break;
        }
    }

    if (isOkay) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }


    return 0;
}
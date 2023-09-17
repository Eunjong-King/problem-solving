#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;

vi parent(1000002);
int N, M;

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

int flat(int x, int y) {
    return M * x + y;
}

int main() {
    FAST_IO;

    cin >> N >> M;

    for (int i = 0; i <= N * M; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        string inp;
        cin >> inp;

        for (int j = 0; j < M; ++j) {
            char c = inp[j];

            int i_adder = 0, j_adder = 0;
            switch (c) {
                case 'D':
                    i_adder = 1;
                    break;
                case 'L':
                    j_adder = -1;
                    break;
                case 'R':
                    j_adder = 1;
                    break;
                case 'U':
                    i_adder = -1;
                    break;
                default:
                    break;
            }

            union_parent(flat(i, j), flat(i + i_adder, j + j_adder));
        }
    }

    int result = 0;
    for (int i = 0; i < N * M; ++i) {
        if (i == parent[i]) {
            result++;
        }
    }
    cout << result << '\n';

    return 0;
}
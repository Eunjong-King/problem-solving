#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(52);

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

bool is_same_parent(int i, int j) {
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

    int T, inp;
    cin >> T;
    vi truth;
    for (int i = 0; i < T; ++i) {
        cin >> inp;
        truth.push_back(inp);
    }

    int man;
    vector<vi> test;
    vi row;
    for (int i = 0; i < M; ++i) {
        row = vi();

        cin >> T;
        for (int j = 0; j < T; ++j) {
            cin >> man;
            row.push_back(man);

            if (j != 0) {
                union_parent(row[0], man);
            }
        }

        test.push_back(row);
    }

    vector<bool> is_truth_man(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        for (int truth_man: truth) {
            if (is_same_parent(i, truth_man)) {
                is_truth_man[i] = true;
                break;
            }
        }
    }

    int count = 0;
    for (auto row1: test) {
        bool isOkay = true;

        for (int i: row1) {
            if (is_truth_man[i]) {
                isOkay = false;
                break;
            }
        }

        if (isOkay) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
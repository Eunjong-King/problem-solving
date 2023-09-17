#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(100002);

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

    int G, P;

    cin >> G >> P;

    for (int i = 0; i <= G; ++i) {
        parent[i] = i;
    }

    int g, result = 0;
    for (int i = 0; i < P; ++i) {
        cin >> g;

        int parent = find_parent(g);
        if (parent == 0) {
            break;
        }

        result++;
        union_parent(parent, parent - 1);
    }

    cout << result << '\n';

    return 0;
}
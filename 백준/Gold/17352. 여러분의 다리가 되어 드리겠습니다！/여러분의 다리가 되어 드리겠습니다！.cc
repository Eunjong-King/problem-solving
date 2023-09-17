#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi parent(300002);

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

    int N;
    cin >> N;

    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }

    int a, b;
    for (int i = 0; i < N - 2; ++i) {
        cin >> a >> b;

        union_parent(a, b);
    }

    vi result;
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == i) {
            result.push_back(i);
        }
    }

    cout << result[0] << ' ' << result[1] << '\n';
    
    return 0;
}
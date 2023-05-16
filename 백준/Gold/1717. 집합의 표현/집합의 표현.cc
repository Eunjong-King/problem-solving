#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int parent[1000001];

int getParent(int a) {
    if (parent[a] == a)return a;

    return parent[a] = getParent(parent[a]);
}

void add(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a > b) parent[a] = b;
    else parent[b] = a;
}


string isSet(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    return a == b ? "YES" : "NO";
}

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int comm, a, b;
    for (int i = 0; i < M; ++i) {
        cin >> comm >> a >> b;

        if (!comm) {
            add(a, b);
        } else {
            cout << isSet(a, b) << '\n';
        }
    }

    return 0;
}
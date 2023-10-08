#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int X, Y;
map<int, vi> m;
bool visited[101];

int dfs(int a, int c) {
    if (a == Y) {
        return c;
    }

    visited[a] = true;

    for (int i: m[a]) {
        if (!visited[i]) {
            int result = dfs(i, c + 1);

            if (result != -1) {
                return result;
            }
        }
    }

    return -1;
}

int main() {
    FAST_IO;

    int N;
    cin >> N >> X >> Y;

    int M;
    cin >> M;

    int x, y;
    while (M--) {
        cin >> x >> y;

        m[x].push_back(y);
        m[y].push_back(x);
    }

    cout << dfs(X, 0) << endl;

    return 0;
}
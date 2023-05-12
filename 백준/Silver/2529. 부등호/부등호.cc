#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int visited[10];
string smin = "9999999999";
string smax = "0";

void dfs(vector<char> &v, int idx, int before, string result) {
    if (idx == N + 1) {
        if (result < smin) {
            smin = result;
        }

        if (result > smax) {
            smax = result;
        }
        return;
    }

    if (v[idx] == '>') {
        for (int i = before - 1; i >= 0; --i) {
            if (visited[i] == 1) {
                continue;
            }

            visited[i] = 1;
            dfs(v, idx + 1, i, result + to_string(i));
            visited[i] = 0;
        }
    } else {
        for (int i = before + 1; i < 10; ++i) {
            if (visited[i] == 1) {
                continue;
            }

            visited[i] = 1;
            dfs(v, idx + 1, i, result + to_string(i));
            visited[i] = 0;
        }
    }


}

int main() {
    FAST_IO;

    cin >> N;
    vector<char> v(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    v[0] = '<';

    dfs(v, 0, -1, "");

    cout << smax << '\n' << smin << '\n';

    return 0;
}
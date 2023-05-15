#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;

int N, M;
char from[50][50];
char to[50][50];

void swap(int x, int y) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            from[x + i][y + j] = from[x + i][y + j] == '1' ? '0' : '1';
        }
    }
}

bool isSame() {
    bool same = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (from[i][j] != to[i][j]) {
                same = false;
                break;
            }
        }

        if (!same) {
            break;
        }
    }

    return same;
}

int main() {
    FAST_IO;

    cin >> N >> M;

    string inp;
    for (int i = 0; i < N; ++i) {
        cin >> inp;
        for (int j = 0; j < inp.size(); ++j) {
            from[i][j] = inp[j];
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> inp;
        for (int j = 0; j < inp.size(); ++j) {
            to[i][j] = inp[j];
        }
    }

    int count = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < M - 2; ++j) {
            if (from[i][j] != to[i][j]) {
                swap(i, j);
                count++;
            }
        }
    }

    if (isSame()) {
        cout << count << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
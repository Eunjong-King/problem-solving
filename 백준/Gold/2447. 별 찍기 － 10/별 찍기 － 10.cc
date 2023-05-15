#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>

using namespace std;

int arr[2188][2188];

void star(int x0, int y0, int len) {
    int oneThird = len / 3;

    if (oneThird == 0) {
        arr[x0][y0] = 1;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }

            star(x0 + oneThird * i, y0 + oneThird * j, oneThird);
        }
    }
}

int main() {
    FAST_IO;

    int N;
    cin >> N;

    star(0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == 1) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
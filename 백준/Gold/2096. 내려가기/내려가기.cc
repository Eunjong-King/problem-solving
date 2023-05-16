#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    int dp1[2][3], dp2[2][3];
    int from_i = 0, to_i = 1;
    int a, b, c;

    for (int i = 0; i < 3; ++i) {
        cin >> a;

        dp1[0][i] = a;
        dp2[0][i] = a;
    }

    for (int i = 1; i < N; ++i) {
        cin >> a >> b >> c;

        dp1[to_i][0] = a + max(dp1[from_i][0], dp1[from_i][1]);
        dp1[to_i][1] = b + max(max(dp1[from_i][0], dp1[from_i][1]), dp1[from_i][2]);
        dp1[to_i][2] = c + max(dp1[from_i][1], dp1[from_i][2]);

        dp2[to_i][0] = a + min(dp2[from_i][0], dp2[from_i][1]);
        dp2[to_i][1] = b + min(min(dp2[from_i][0], dp2[from_i][1]), dp2[from_i][2]);
        dp2[to_i][2] = c + min(dp2[from_i][1], dp2[from_i][2]);

        swap(from_i, to_i);
    }

    cout << max(max(dp1[from_i][0], dp1[from_i][1]), dp1[from_i][2]) << ' ';
    cout << min(min(dp2[from_i][0], dp2[from_i][1]), dp2[from_i][2]) << '\n';

    return 0;
}
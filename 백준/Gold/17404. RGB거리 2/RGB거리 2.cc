#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int dp[1002][3];
int color[1002][3];

int main() {
    FAST_IO;

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> color[i][j];
        }
    }

    int result = 2000000;
    for (int RGB = 0; RGB < 3; ++RGB) {
        for (int i = 0; i < 3; ++i) {
            if (i == RGB) {
                dp[1][i] = color[1][i];
            } else {
                dp[1][i] = 2000000;
            }
        }

        for (int i = 2; i <= N; ++i) {
            dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        for (int i = 0; i < 3; ++i) {
            if (i == RGB) continue;

            result = min(result, dp[N][i]);
        }
    }

    cout << result << '\n';

    return 0;
}
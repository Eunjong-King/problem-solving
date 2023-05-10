#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    vector<vi> dp(N, vi(10, 0));

    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[N - 1][i];
        sum %= 10007;
    }
    cout << sum << '\n';

    return 0;
}
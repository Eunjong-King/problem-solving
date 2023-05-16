#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N, K;
    cin >> N >> K;

    int dp[10001];
    vi coins(N);

    fill_n(dp, K + 1, K + 1);

    for (int i = 0; i < N; ++i) {
        cin >> coins[i];

        if (coins[i] > K) {
            continue;
        }

        dp[coins[i]] = 1;
    }

    for (int i = 1; i <= K; ++i) {
        for (int c: coins) {
            if (i - c < 0) {
                continue;
            }

            if (dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
            }
        }
    }

    if (dp[K] == K + 1) {
        cout << -1 << '\n';
    } else {
        cout << dp[K] << '\n';
    }

    return 0;
}
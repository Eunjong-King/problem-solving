#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    vector<vi> v(N, vi(N));
    vector<vector<ll>> dp(N, vector<ll>(N, 0LL));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = 1LL;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] == 0 || v[i][j] == 0) {
                continue;
            }

            if (i + v[i][j] < N) {
                dp[i + v[i][j]][j] += (ll)dp[i][j];
            }

            if (j + v[i][j] < N) {
                dp[i][j + v[i][j]] += (ll)dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << '\n';

    return 0;
}
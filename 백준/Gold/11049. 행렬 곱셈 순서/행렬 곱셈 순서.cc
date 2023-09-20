#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int dp[2001][2001];
pair<int, int> arr[2001];

int main() {
    FAST_IO;

    int N;
    cin >> N;

    int a, b;
    for (int i = 1; i <= N; ++i) {
        cin >> a >> b;
        arr[i] = {a, b};
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; i + j <= N; ++j) {
            dp[j][i + j] = 2100000000;
            for (int k = j; k <= i + j; ++k) {
                dp[j][i + j] = min(dp[j][i + j],
                                   dp[j][k] + dp[k + 1][i + j] + arr[j].first * arr[k].second * arr[i + j].second);
            }
        }
    }

    cout << dp[1][N] << '\n';

    return 0;
}
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

    vector<pair<int, int>> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int dp[N + 1];
    dp[0] = 0;
    int max_dp = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = 1;

        for (int j = 1; j < i; ++j) {
            if (v[i].second > v[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if (max_dp < dp[i]) {
            max_dp = dp[i];
        }
    }

    cout << N - max_dp << '\n';

    return 0;
}
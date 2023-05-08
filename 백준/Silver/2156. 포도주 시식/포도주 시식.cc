#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
    int N;
    cin >> N;

    vi v(N+1);
    for(int i=1; i<=N; i++) {
        cin >> v[i];
    }

    if(N == 1) {
        cout << v[1] << endl;
        return 0;
    }

    vector<vector<int>> dp(N+2, vector<int>(2, 0));
    dp[2][0] = v[1];
    dp[2][1] = v[1];

    for(int i=3; i<=N+1; i++) {
        dp[i][0] = max(max(dp[i-2][1], dp[i-2][0]), dp[i-3][1]) + v[i-1];
        dp[i][1] = dp[i-1][0] + v[i-1];
    }

    int MAX = max(max(dp[N+1][0], dp[N+1][1]), dp[N][1]);
    cout << MAX << endl;

    return 0;
}
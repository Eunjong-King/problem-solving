#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
    int N;
    cin >> N;

    vi v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    vi dp(N, 0);
    dp[0] = v[0];
    for(int i=1; i<N; i++) {
        dp[i] = max(v[i], dp[i-1] + v[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
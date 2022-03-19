#include <iostream>
using namespace std;

int N, K;
int dp[201][201];

void solve(){
    for(int i=0; i<=K; i++){
        dp[1][i] = i;
    }

    for(int k=1; k<=K; ++k){
        for(int n=2; n<=N; ++n){
            dp[n][k] = (dp[n][k-1] + dp[n-1][k]) % 1000000000;
        }
    }

    cout << dp[N][K] << '\n';
}

int main(void){
    cin >> N >> K;

    solve();

    return 0;
}
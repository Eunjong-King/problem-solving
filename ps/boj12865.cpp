#include <iostream>
using namespace std;

int dp[101][100001];
int weight[101];
int value[101];

int main(void){
    int N, K, W, V;
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j < weight[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}
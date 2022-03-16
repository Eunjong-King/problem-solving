#include <iostream>
using namespace std;

int main(void){
    int dp[32];
    dp[2] = 3;

    int N;
    cin >> N;
    if(N % 2 == 1){
        cout << 0 << endl;
    }
    else{
        int temp, res;
        for(int i=4; i<=N; i+=2){
            temp = i-2;
            res = 2 + dp[temp] * dp[2];
            temp -= 2;
            while(temp > 0){
                res += dp[temp] * 2;
                temp -= 2;
            }
            dp[i] = res;
        }
        cout << dp[N] << endl;
    }

    return 0;
}

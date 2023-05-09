#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> v(N, vector<int>(10, 0));
    for(int j=1; j<=9; j++) {
        v[0][j] = 1;
    }

    for(int i=1; i<N; i++) {
        for(int j=0; j<=9; j++) {
            if(j == 0) {
                v[i][0] = v[i-1][1];
            } else if(j == 9) {
                v[i][9] = v[i-1][8];
            } else {
                v[i][j] = ((v[i-1][j-1])%1000000000 + v[i-1][j+1]%1000000000)%1000000000;
            }
        }
    }

    int sum = 0;
    for(int j=0; j<=9; j++) {
        sum += v[N-1][j];
        sum %= 1000000000;
    }
    cout << sum << '\n';

    return 0;
}
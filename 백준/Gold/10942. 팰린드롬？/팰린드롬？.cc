#include <iostream>
#include <algorithm>

using namespace std;

int dp[2001][2001];
int arr[2001];

int palin(int a, int b) {
	if(a > b) {
		return 1;
	}
	
	if(dp[a][b] != 2) {
		return dp[a][b];
	}
	
	if(arr[a] == arr[b]) {
		int result = palin(a+1, b-1);
		dp[a][b] = result;
		return result;
	} else {
		dp[a][b] = 0;
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if(i == j) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 2;
			}
		}
	}
	
	int M;
	cin >> M;
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		
		cout << palin(a, b) << '\n';
	}
}
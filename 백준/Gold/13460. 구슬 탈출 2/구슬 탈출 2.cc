#include <iostream>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char arr[10][10];
bool visit[11][11][11][11];
vector<pair<int, int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isRedFirst(pii R, pii B, int move) {
	bool result = true;
	int RI = R.first, RJ = R.second, BI = B.first, BJ = B.second;
	
	if(move == 0) {
		if(RJ == BJ && BI > RI) { 
			result = false;
		}
	} else if(move == 1){
		if(RJ == BJ && BI < RI) {
			result = false;
		}
	} else if(move == 2) {
		if(RI == BI && BJ > RJ) {
			result = false;
		}
	} else {
		if(RI == BI && BJ < RJ) {
			result = false;
		}
	}
	
	return result;
}

bool moving(pii& A, pii B, int i) {
	int movei = moves[i].first;
	int movej = moves[i].second;
	
	int AI=A.first, AJ=A.second, BI=B.first, BJ=B.second;
	
	while(true) {
		AI += movei;
		AJ += movej;
		
		if(arr[AI][AJ] == '#' || (AI == BI && AJ == BJ)) {
			A = {AI-movei, AJ-movej};
			return false;
		}
		if(arr[AI][AJ] == 'O') {
			A = {0, 0};
			return true;
		}
	}
}

int bfs(pii R, pii B) {
	int result = -1, cost;
	bool resultR, resultB;
	queue<vector<int>> q;
	
	q.push({R.first, R.second, B.first, B.second, 0});
	
	while(!q.empty()) {
		vector<int> front = q.front();
		
		cost = front[4];
		
		for(int i=0; i<4; i++) {
			pii newR = {front[0], front[1]};
			pii newB = {front[2], front[3]};
			
			if(isRedFirst(newR, newB, i)) {
				resultR = moving(newR, newB, i);
				resultB = moving(newB, newR, i);
			} else {
				resultB = moving(newB, newR, i);
				resultR = moving(newR, newB, i);
			}
			
			if(resultB == true) {
				continue;
			}
			
			if(resultR == true) {
				return cost + 1; 
			} else {
				if(visit[newR.first][newR.second][newB.first][newB.second]) {
					continue;
				}
				if(cost < 9) {
					visit[newR.first][newR.second][newB.first][newB.second] = true;
					q.push({newR.first, newR.second, newB.first, newB.second, cost+1});
				}
			}
		}
		
		q.pop();
	}
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	string inp;
	pii R, B;
	for (int i = 0; i < N; ++i) {
		cin >> inp;
		for (int j = 0; j < M; ++j) {
			arr[i][j] = inp[j];
			
			if(inp[j] == 'R') {
				R = {i, j};
			} else if(inp[j] == 'B') {
				B = {i, j};
			}
		}
	}
	
	cout << bfs(R, B) << '\n';
	
	return 0;
}


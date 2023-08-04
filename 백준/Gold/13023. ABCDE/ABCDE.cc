#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef map<int, vector<int>> mvi;

mvi m;
bool checker[2002];

bool dfs(int from, int count) {
	if(count >= 5) {
		return true;
	}
	
	for(auto i : m[from]) {
		if(!checker[i]) {
			checker[i] = true;
			
			bool result = dfs(i, count+1);
			
			if(result) {
				return true;
			}
			checker[i] = false;
		}
	}
	
	return false;
}

int main() {
	int N, M;
	
	cin >> N >> M;
	
	int a, b;
	for(int i=0; i<M; i++) {
		cin >> a >> b;
		
		m[a].push_back(b);
		m[b].push_back(a);
	}
	
	for(int i=0; i<N; i++) {
		checker[i] = true;
		bool result = dfs(i, 1);
		
		if(result) {
			cout << "1" << endl;
			return 0;
		}
		
		checker[i] = false;
	}
	
	cout << "0" << endl;
	
	return 0;
}
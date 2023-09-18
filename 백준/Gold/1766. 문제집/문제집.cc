#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;

vi topo(32002);

int main() {
	int N, M;
	cin >> N >> M;
	
	int a, b;
	map<int, vi> m;
	for(int i=0; i<M; i++) {
		cin >> a >> b;
		
		m[a].push_back(b);
		topo[b]++;
	}
	
	priority_queue<int, vi, greater<int>> pq;
	for(int i=1; i<=N; i++) {
		if(topo[i] == 0) {
			pq.push(i);
		}
	}
	
	while(!pq.empty()) {
		int front = pq.top();
		pq.pop();
		
		cout << front << ' ';
		
		for(int i : m[front]) {
			topo[i]--;
			
			if(topo[i] == 0) {
				pq.push(i);
			}
		}
		
	}
	cout << '\n';
	
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10003];

bool compare(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
	return p1.second < p2.second;
}

int find_parent(int a) {
	if(a == parent[a]) {
		return a;
	}
	
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	
	parent[b] = a;
}

bool is_same_parent(int a, int b) {
	return find_parent(a) == find_parent(b);
}

int main() {
	int V, E;
	
	cin >> V >> E;
	
	vector<pair<pair<int, int>, int>> v(E);
	
	for(int i=0; i<=10002; i++) {
		parent[i] = i;
	}
	
	int v1, v2, cost;
	for(int i=0; i<E; i++) {
		cin >> v1 >> v2 >> cost;
		
		v[i] = {{v1, v2}, cost};
	}
	
	sort(v.begin(), v.end(), compare);

	int total = 0;
	for(auto a : v) {
		if(is_same_parent(a.first.first, a.first.second)) {
			continue;
		}
		
		total += a.second;
		
		union_parent(a.first.first, a.first.second);
	}
	
	cout << total << endl;
	
	return 0;
}
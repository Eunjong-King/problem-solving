#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

vi parent(100002);

int find_parent(int a) {
	if(a == parent[a]) {
		return a;
	}
	
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
	int arep = find_parent(a);
	int brep = find_parent(b);
	
	parent[arep] = brep;
}


int main() {
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++) {
		parent[i] = i;
	}
	
	vpi x_vec(N);
	vpi y_vec(N);
	vpi z_vec(N);
	
	int x, y, z;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> z;
		
		x_vec[i] = {x, i};
		y_vec[i] = {y, i};
		z_vec[i] = {z, i};
	}
	
	sort(x_vec.begin(), x_vec.end());
	sort(y_vec.begin(), y_vec.end());
	sort(z_vec.begin(), z_vec.end());
	
	vector<pair<int, pair<int, int>>> edges(3*(N-1));
	for(int i=0; i<N-1; i++) {
		edges[i*3] = {x_vec[i+1].first - x_vec[i].first, {x_vec[i].second, x_vec[i+1].second}};
		edges[i*3+1] = {y_vec[i+1].first - y_vec[i].first, {y_vec[i].second, y_vec[i+1].second}};
		edges[i*3+2] = {z_vec[i+1].first - z_vec[i].first, {z_vec[i].second, z_vec[i+1].second}};
	}
	
	sort(edges.begin(), edges.end());
	
	int result=0, a, b;
	for(auto edge : edges) {
		a = edge.second.first;
		b = edge.second.second;
		
		if(find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += edge.first;
		}
	}
	cout << result << '\n';
	
	return 0;
}
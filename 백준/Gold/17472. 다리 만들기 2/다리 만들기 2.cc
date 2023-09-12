#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> v(10, vector<int>(10));
vector<pair<int, int>> adders = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<int> parent(10002);

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

void bfs(int i, int j, int marker) {
	queue<pair<int, int>> q;
	
	q.push({i, j});
	
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		
		v[p.first][p.second] = marker;
		
		for(auto a : adders) {
			int newi = p.first + a.first;
			int newj = p.second + a.second;
			
			if(newi >= 0 && newi < N && newj >= 0 && newj < M) {
				if(v[newi][newj] == 1) {
					q.push({newi, newj});
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}
	
	int marker = 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if(v[i][j] == 1) {
				bfs(i, j, marker);
				marker++;
			}
		}
	}
	
	map<pair<int, int>, int> m;
	int start, len;
	for (int i = 0; i < N; ++i) {
		start = v[i][0];
		len = 0;
		for (int j = 1; j < M; ++j) {
			if(v[i][j] == 0) {
				len++;
			}
			else if(v[i][j] != 0 && v[i][j] != start) {
				if(start != 0 && len > 1) {
					if(m[{start, v[i][j]}] == 0) {
						m[{start, v[i][j]}] = len;
					} else {
						m[{start, v[i][j]}] = min(m[{start, v[i][j]}], len);
					}
				}
				start = v[i][j];
				len = 0;
			}
			else {
				len = 0;
			}
		}
	}
	for (int j = 0; j < M; ++j) {
		start = v[0][j];
		len = 0;
		for (int i = 1; i < N; ++i) {
			if(v[i][j] == 0) {
				len++;
			}
			else if(v[i][j] != 0 && v[i][j] != start) {
				if(start != 0 && len > 1) {
					if(m[{start, v[i][j]}] == 0) {
						m[{start, v[i][j]}] = len;
					} else {
						m[{start, v[i][j]}] = min(m[{start, v[i][j]}], len);
					}
				}
				start = v[i][j];
				len = 0;
			}
			else {
				len = 0;
			}
		}
	}
	
	for(int i=0; i<marker+3; i++) {
		parent[i] = i;
	}
	
	vector<pair<int, pair<int, int>>> edges;
	for(auto a : m) {
		// cout << a.first.first << ", " << a.first.second << " -> " << a.second << '\n';
		edges.push_back({a.second, {a.first.first, a.first.second}});
	}
	
	sort(edges.begin(), edges.end());
	
	// for(auto edge : edges) {
	// 	cout << edge.first << " -> " << edge.second.first << ", " << edge.second.second << '\n';
	// }
	
	int result = 0;
	int total_island = 0;
	for(auto edge : edges) {
		int a = edge.second.first;
		int b = edge.second.second;
		
		if(find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += edge.first;
			total_island++;
		}
	}
	
	if(result == 0 || total_island != marker-3) {
		cout << -1 << '\n';
	} else {
		cout << result << '\n';
	}
	
	return 0;
}
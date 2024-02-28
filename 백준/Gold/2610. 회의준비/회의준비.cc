/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> parent(101);

int find_parent(int x) {
    if(x == parent[x]) {
        return x;
    }
    
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    
    if(x == y) return;
    
    parent[x] = y;
    
    return;
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    for(int i=1; i<=N; i++) {
        parent[i] = i;
    }
        
    vector<vector<int>> dist(N+1, vector<int>(N+1, 1e9));
    
    int a, b;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        
        union_parent(a, b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    for(int mid=1; mid<=N; mid++) {
        for(int from=1; from<=N; from++) {
            for(int to=1; to<=N; to++) {
                if(dist[from][to] > dist[from][mid] + dist[mid][to]) {
                    dist[from][to] = dist[from][mid] + dist[mid][to];
                }
            }
        }
    }
    
    map<int, pair<int, int>> result;
    for(int i=1; i<=N; i++) {
        if(find_parent(i) == i) {
            result[i] = {1e9, i};
        }
    }
    
    
    for(int i=1; i<=N; i++) {
        int maximum = 0;
        for(int j=1; j<=N; j++) {
            if(i == j) continue;
            
            if(parent[i] == parent[j]) {
                maximum = max(maximum, dist[i][j]);
            }
        }
        
        if(result[parent[i]].first > maximum) {
            result[parent[i]] = {maximum, i};
        }
    }
    
    vector<int> answer;
    cout << result.size() << endl;
    for(auto a : result) {
        answer.push_back(a.second.second);
    }
    
    sort(answer.begin(), answer.end());
    
    for(auto a : answer) {
        cout << a << endl;
    }

    return 0;
}

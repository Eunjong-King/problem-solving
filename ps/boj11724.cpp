#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

map<int, vector<int>> m;
set<int> s;

void bfs(int node){
    queue<int> q;
    
    for (int i : m[node]){
        q.push(i);
        s.insert(i);
    }
    s.insert(node);

    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();

        for (int i : m[now]){
            if (s.find(i) == s.end()){
                q.push(i);
                s.insert(i);
            }
        }
    }
}

int main(void){
    int N, M, u, v, count = 0;
    cin >> N >> M;

    for (int i=0; i<M; i++){
        cin >> u >> v;

        m[u].push_back(v);
        m[v].push_back(u);
    }

    for(int i=1; i<=N; i++){
        if (s.find(i) == s.end()){
            bfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
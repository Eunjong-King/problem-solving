#include <iostream>
#include <queue>
using namespace std;

int N, M;

void dfs(queue<int> q, int depth, int prev){
    if(depth >= M){
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
        return;
    }
    
    for(int i=prev; i<=N; i++){
        queue<int> newQ = q;
        newQ.push(i);
        dfs(newQ, depth+1, i);
    }
}

int main(void){
    cin >> N >> M;

    dfs({}, 0, 0);
}
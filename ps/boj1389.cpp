#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

map<int, set<int>> m;

int bfs(int f_p, int t_p){
    int count = 0;
    queue<pair<int, int>> q;
    set<int> s;

    for(int a : m[f_p]){
        q.push({a, 1});
        s.insert(a);
    }

    int now, index=2;
    while(!q.empty()){
        now = q.front().first;
        count = q.front().second;
        q.pop();

        if (now == t_p){
            break;
        }

        for(int a : m[now]){
            if (s.find(a) == s.end()){
                q.push({a, count+1});
            }
        }
    }

    return count;
}

int main(void){
    int N, M, A, B;
    cin >> N >> M;
    int min_bacon_count = 2147483647, min_person = N+2;

    for (int i=0; i<M; i++){
        cin >> A >> B;
        m[A].insert(B);
        m[B].insert(A);
    }

    int bacon_count;
    for (int i=1; i<=N; i++){
        bacon_count = 0;
        for (int j=1; j<=N; j++){
            if (i==j) continue;
            bacon_count += bfs(i, j);
        }

        if (bacon_count < min_bacon_count){
            min_bacon_count = bacon_count;
            min_person = i;
        }
    }

    cout << min_person << endl;
    
    return 0;
}
#include <queue>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main(void){
    int N, M, x, y;
    cin >> N >> M;
    map<int, int> m;

    for (int i=0; i<N+M; i++){
        cin >> x >> y;
        m[x] = y;
    }

    queue<pair<int, int>> q;
    set<int> s;
    q.push({1, 0});
    s.insert(1);

    int temp, tr;
    while(!q.empty()){
        tie(temp, tr) = q.front();
        q.pop();

        for(int i=1; i<=6; i++){
            if(s.find(temp+i) == s.end()){
                if (m.count(temp+i) == 0){
                    if (temp+i == 100){
                        cout << tr+1 << endl;
                        goto L;
                    }
                    q.push({temp+i, tr+1});
                    s.insert(temp+i);
                }
                else{
                    if (m[temp+i] == 100){
                        cout << tr+1 << endl;
                        goto L;
                    }
                    q.push({m[temp+i], tr+1});
                    s.insert(temp+i);
                    s.insert(m[temp+i]);
                }
            }
        }
    }
    L:

    return 0;
}
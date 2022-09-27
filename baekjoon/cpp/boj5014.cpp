#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool mask[1000003];

void input(){
    cin >> F >> S >> G >> U >> D;

    return;
}

void bfs(){
    if(S == G){
        cout << 0 << endl;
        return;
    }

    queue<pair<int, int>> q;
    q.push({S, 0});
    mask[S] = true;

    int now, time, next1, next2;
    while(!q.empty()){
        now = q.front().first;
        time = q.front().second;
        q.pop();

        next1 = now + U;
        next2 = now - D;

        if(next1 <= F && mask[next1] == false){
            q.push({next1, time+1});
            mask[next1] = true;
            if(next1 == G){
                cout << time + 1 << endl;
                break;
            }
        }
        if(next2 >= 1 && mask[next2] == false){
            q.push({next2, time+1});
            mask[next2] = true;
            if(next2 == G){
                cout << time + 1 << endl;
                break;
            }
        }
    }

    if(q.empty()){
        cout << "use the stairs" << endl;
    }

    return;
}

void solve(){
    input();

    bfs();

    return;
}

int main(void){
    solve();

    return 0;
}
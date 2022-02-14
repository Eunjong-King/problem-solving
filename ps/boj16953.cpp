#include <iostream>
#include <queue>
using namespace std;

int A, B;

void bfs(){
    queue<pair<int, int>> q;
    q.push({A, 1});

    bool breaker = false;
    int top, count, temp;
    while(!q.empty()){
        top = q.front().first;
        count = q.front().second;
        q.pop();

        if(top == B){
            cout << count << endl;
            breaker = true;
            break;
        }
        
        if(top < 1073741824){
            if(top*2 <= B){
                q.push({top*2, count+1});
            }
        }
        if(top < 214748365){
            if(top*10+1 <= B){
                q.push({top*10+1, count+1});
            }
        }
    }

    if(!breaker){
        cout << -1 << endl;
    }
}

int main(void){
    cin >> A >> B;

    bfs();

    return 0;
}
#include <stack>
#include <cstdio>
using namespace std;

int N;
stack<pair<int, int>> s;

void input(){
    scanf("%d", &N);

    return;
}

void solve(){
    input();

    int height;
    pair<int, int> p;
    for(int i=1; i<=N; i++){
        scanf("%d", &height);
        if(s.empty()){
            printf("0 ");
        }
        else{
            while(!s.empty()){
                p = s.top();
                if(p.first > height){
                    printf("%d ", p.second);
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                printf("0 ");
            }
        }
        s.push({height, i});
    }

    return;
}

int main(void){
    solve();

    return 0;
}
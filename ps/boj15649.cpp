#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void solve(vector<int> v, int depth){
    if(depth == M){
        for(int i : v){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++){
        if(find(v.begin(), v.end(), i) == v.end()){
            vector<int> temp = v;
            temp.push_back(i);
            solve(temp, depth+1);
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    solve({}, 0);

    return 0;
}
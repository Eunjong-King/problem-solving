#include <queue>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int N, M;
set<int> s;

void dfs(string myString, vector<int> prev, int depth){
    if(depth == M){
        cout << myString << '\n';
        return;
    }
    for(int i : s){
        if(find(prev.begin(), prev.end(), i) == prev.end()){
            vector<int> tempV = prev;
            tempV.push_back(i);
            if (myString.length() == 0){
                dfs(to_string(i), tempV, depth+1);
            }
            else{
                dfs(myString+' '+to_string(i), tempV, depth+1);
            }
        }
    }
}

int main(void){
    int t;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> t;
        s.insert(t);
    }

    dfs("", {}, 0);
}
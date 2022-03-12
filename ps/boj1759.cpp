#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int L, C;
vector<char> v;
map<char, bool> m;

void input(){
    cin >> L >> C;
    char temp;
    for(int i=0; i<C; i++){
        cin >> temp;
        v.push_back(temp);
        if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
            m[temp] = true;
        }
        else{
            m[temp] = false;
        }
    }
    return;
}

void dfs(int depth, string str, int index, int ja, int mo){
    if(depth == L){
        if(ja < 2 || mo < 1){
            return;
        }
        cout << str << endl;
    }
    for(int i=index; i<C; i++){
        if(m[v[i]]){
            dfs(depth+1, str+v[i], i+1, ja, mo+1);
        }
        else{
            dfs(depth+1, str+v[i], i+1, ja+1, mo);
        }
    }
    return;
}

void solve(){
    sort(v.begin(), v.end());
    dfs(0, "", 0, 0, 0);
}

int main(void){
    input();
    solve();
}
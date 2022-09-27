#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int M;
vector<int> v;

void dfs(string s, list<int> li, int depth){
    if(depth == M){
        cout << s << '\n';
        return;
    }

    int prev = -1;
    for(int i : v){
        if(prev == i){
            continue;
        }
        prev = i;

        list<int> next = li;
        auto it = find(next.begin(), next.end(), i);
        if(it == next.end()){
            continue;
        }
        else{
            next.erase(it);
        }

        if(s.length() == 0){
            dfs(to_string(i), next, depth+1);
        }
        else{
            dfs(s+' '+to_string(i), next, depth+1);
        }
    }
}

int main(void){
    int N, temp;
    cin >> N >> M;
    list<int> li;

    for(int i=0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
        li.push_back(temp);
    }

    sort(v.begin(), v.end());

    dfs("", li, 0);

    return 0;
}
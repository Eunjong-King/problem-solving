#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int* iarr = new int[N+1];
    bool* barr = new bool[N+1];
    fill_n(barr, N+1, false);

    int f, s;
    map<int, vector<int>> m;
    queue<int> q;
    for(int i=0; i<N-1; i++){
        cin >> f >> s;
        m[f].push_back(s);
        m[s].push_back(f);
    }
    q.push(1);
    barr[1] = true;
    while(!q.empty()){
        f = q.front();
        q.pop();

        for(int i : m[f]){
            if(barr[i] == false){
                iarr[i] = f;
                q.push(i);
                barr[i] = true;
            }
        }
    }

    for(int i=2; i<N+1; i++){
        cout << iarr[i] << '\n';
    }

    delete[] iarr;
    delete[] barr;
    return 0;
}
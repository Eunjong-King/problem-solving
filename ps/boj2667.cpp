#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<pair<int, int>> s;
char** c = NULL;
int N;

int bfs(int i, int j){
    queue<pair<int, int>> q;
    int count = 0;

    q.push({i, j});
    count++;
    s.insert({i, j});

    int ti, tj, tti, ttj;
    while(!q.empty()){
        tie(ti, tj) = q.front();
        q.pop();

        for (pair<int, int> adder : adders){
            tti = ti + adder.first;
            ttj = tj + adder.second;

            if (tti >= 0 && tti < N && ttj >= 0 && ttj < N){
                if(c[tti][ttj] == '1' && s.find({tti, ttj}) == s.end()){
                    q.push({tti, ttj});
                    count++;
                    s.insert({tti, ttj});
                }
            }
        }
    }

    return count;
}

int main(void){
    cin >> N;

    c = new char* [N];
    for(int i=0; i<N; i++){
        c[i] = new char[N];
    }

    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        for(int j=0; j<N; j++){
            c[i][j] = row[j];
        }
    }

    vector<int> result;
    int time_count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (c[i][j] == '1' && s.find({i, j}) == s.end()){
                result.push_back(bfs(i, j));
                time_count++;
            }
        }
    }

    sort(result.begin(), result.end());

    cout << time_count << endl;
    for(int i : result){
        cout << i << endl;
    }

    for(int i=0; i<N; i++){
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
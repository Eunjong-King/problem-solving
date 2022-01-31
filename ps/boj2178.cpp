#include <set>
#include <queue>
#include <tuple>
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;

    bool** b = new bool*[N];
    for (int i=0; i<N; i++){
        b[i] = new bool[M];
    }

    string row;
    for (int i=0; i<N; i++){
        cin >> row;
        for(int j=0; j<M; j++){
            if (row[j] == '1'){
                b[i][j] = true; 
            }
            else{
                b[i][j] = false;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    set<pair<int, int>> s;
    q.push({0, 0, 1});
    s.insert({0, 0});

    tuple<int, int, int> temp;
    int x, y, z, tempX, tempY;
    vector<pair<int, int>> adders = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        tie(x, y, z) = q.front();
        q.pop();
        for (auto adder : adders){
            tempX = x + adder.first;
            tempY = y + adder.second;

            if ((s.find({tempX, tempY}) == s.end()) && tempX >= 0 && tempX < N && tempY >= 0 && tempY < M){
                if (b[tempX][tempY]){
                    if (tempX == N-1 && tempY == M-1){
                        cout << z+1 << endl;
                        goto L;
                    }
                    q.push({tempX, tempY, z+1});
                    s.insert({tempX, tempY});
                }
            }
        }
    }
    L:
    for(int i=0; i<N; i++){
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
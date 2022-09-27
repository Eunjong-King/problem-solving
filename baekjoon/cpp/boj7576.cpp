#include <queue>
#include <set>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(void){
    int M, N;
    cin >> M >> N;

    int** arr = new int*[N];
    for(int i=0; i<N; i++){
        arr[i] = new int[M];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1){
                q.push({i, j, 0});
            }
        }
    }

    int fi, fj, day, tempi, tempj;
    while(!q.empty()){
        tie(fi, fj, day) = q.front();
        q.pop();

        for(auto adder : adders){
            tempi = fi + adder.first;
            tempj = fj + adder.second;

            if(tempi >= 0 && tempi < N && tempj >= 0 && tempj < M){
                if(arr[tempi][tempj] == 0){
                    arr[tempi][tempj] = 1;
                    q.push({tempi, tempj, day+1});
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0){
                cout << -1 << endl;
                goto L;
            }
        }
    }
    cout << day << endl;

    L:
    for(int i=0; i<N; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
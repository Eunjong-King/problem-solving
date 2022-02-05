#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main(void){
    int M, N, H;
    cin >> M >> N >> H;

    int*** arr = new int**[H];
    for(int i=0; i<H; i++){
        arr[i] = new int*[N];
        for(int j=0; j<N; j++){
            arr[i][j] = new int[M];
        }
    }
    
    queue<tuple<int, int, int, int>> q;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({i, j, k, 0});
                }
            }
        }
    }

    vector<tuple<int, int, int>> adder{{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    int i, j, k, day, ti, tj, tk;
    while(!q.empty()){
        tie(i, j, k, day) = q.front();
        q.pop();

        for(tuple<int, int, int> t : adder){
            ti = i + get<0>(t);
            tj = j + get<1>(t);
            tk = k + get<2>(t);
            if(ti >= 0 && tj >= 0 && tk >= 0 && ti < H && tj < N && tk < M){
                if(arr[ti][tj][tk] == 0){
                    q.push({ti, tj, tk, day+1});
                    arr[ti][tj][tk] = 1;
                }
            }
        }
    }

    bool breaker = false;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(arr[i][j][k] == 0){
                    cout << -1 << endl;
                    breaker = true;
                    goto L;
                }
            }
        }
    }
    L:
    if (!breaker){
        cout << day << endl;
    }


    // cout << "\n";
    // for(int i=0; i<H; i++){
    //     for(int j=0; j<N; j++){
    //         for(int k=0; k<M; k++){
    //             cout << arr[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n\n";
    // }

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            delete[] arr[i][j];
        }
    }
    for(int i=0; i<H; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
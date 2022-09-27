#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

char arr[50][50];
bool mask[50][50];
int N, M;
vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void mask_init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            mask[i][j] = false;
        }
    }

    return;
}

int bfs(int& x, int& y){
    mask_init();
    mask[x][y] = true;
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});


    int now_x, now_y, new_x, new_y, hour;
    while(!q.empty()){
        tie(now_x, now_y, hour) = q.front();
        q.pop();

        for(auto adder : adders){
            new_x = now_x + adder.first;
            new_y = now_y + adder.second;

            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && arr[new_x][new_y] == 'L' && mask[new_x][new_y] == false){
                mask[new_x][new_y] = true;
                q.push({new_x, new_y, hour+1});
            }
        }
    }

    return hour;
}

int main(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int max_hour = 0, hour;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'L'){
                hour = bfs(i, j);
                if(max_hour < hour){
                    max_hour = hour;
                }
            }
        }
    }

    cout << max_hour << endl;

    return 0;
}
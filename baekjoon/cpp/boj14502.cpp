#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

queue<pair<int, int>> virus;
vector<pair<int, int>> space;
vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arr[10][10];
int new_arr[10][10];
int N, M, space_max;

void get_safe_space(){
    int count=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(new_arr[i][j] == 0){
                ++count;
            }
        }
    }

    if(count > space_max){
        space_max = count;
    }

    return;
}

void virus_spread(){
    queue<pair<int, int>> new_virus = virus;
    int x, y, new_x, new_y;
    while(!new_virus.empty()){
        x = new_virus.front().first;
        y = new_virus.front().second;
        new_virus.pop();

        for(auto adder : adders){
            new_x = x + adder.first;
            new_y = y + adder.second;

            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M){
                if(new_arr[new_x][new_y] == 0){
                    new_virus.push({new_x, new_y});
                    new_arr[new_x][new_y] = 2;
                }
            }
        }
    }

    get_safe_space();

    return;
}

void copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            new_arr[i][j] = arr[i][j];
        }
    }
}

void get_three(vector<pair<int, int>> v, int depth, int index){
    if(depth == 3){
        copy();
        for(auto p : v){
            new_arr[p.first][p.second] = 1;
        }
        virus_spread();
        return;
    }
    for(int i=index; i<space.size(); i++){
        vector<pair<int, int>> tempv = v;
        tempv.push_back(space[i]);
        get_three(tempv, depth+1, i+1);
    }
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                virus.push({i, j});
            }
            else if(arr[i][j] == 0){
                space.push_back({i, j});
            }
        }
    }

    return;
}

int main(void){
    input();
    get_three({}, 0, 0);

    cout << space_max << '\n';

    return 0;
}
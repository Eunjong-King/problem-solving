#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L, R;
int arr[50][50];
int mask[50][50];
vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void input(){
    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    return;
}

int bfs(int x, int y){
    vector<pair<int, int>> history;
    queue<pair<int, int>> q;
    q.push({x, y});
    mask[x][y] = 1;

    pair<int, int> p;
    int new_x, new_y, diff;
    int total_value = 0;
    while(!q.empty()){
        p = q.front();
        q.pop();
        total_value += arr[p.first][p.second];
        history.push_back({p.first, p.second});

        for(auto adder : adders) {
            new_x = p.first + adder.first;
            new_y = p.second + adder.second;

            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N){
                diff = abs(arr[p.first][p.second]-arr[new_x][new_y]);
                if(L <= diff && diff <= R && mask[new_x][new_y] == 0){
                    q.push({new_x, new_y});
                    mask[new_x][new_y] = 1;
                }
            }
        }
    }

    if(history.size() == 1){
        return 0;
    }

    int average = total_value / history.size();
    for(auto p : history){
        arr[p.first][p.second] = average;
    }
    return 1;
}

void mask_init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mask[i][j] = 0;
        }
    }
}

bool search(){
    int change_count = 0;
    mask_init();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mask[i][j] == 0){
                change_count += bfs(i, j);
            }
        }
    }
    if(change_count == 0){
        return false;
    }
    else{
        return true;
    }
}

void solve(){
    input();

    bool checker;
    int counter = 0;
    while(true) {
        checker = search();
        if(checker){
            ++counter;
        }
        else{
            break;
        }
    }
    cout << counter << endl;

    return;
}

int main(void){
    solve();

    return 0;
}
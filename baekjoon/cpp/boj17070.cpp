#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

enum Form {ROW, DIA, COL};
int N;
int arr[17][17], dp[17][17];
vector<tuple<int, int, Form>> row_v{{0, 1, ROW}, {1, 1, DIA}};
vector<tuple<int, int, Form>> dia_v{{0, 1, ROW}, {1, 1, DIA}, {1, 0, COL}};
vector<tuple<int, int, Form>> col_v{{1, 0, COL}, {1, 1, DIA}};

void bfs(){
    queue<tuple<int, int, Form>> q;
    q.push({0, 1, ROW});

    int x, y, new_x, new_y, count=0;
    Form f;
    while(!q.empty()){
        tie(x, y, f) = q.front();
        q.pop();

        if(x == N-1 && y == N-1){
            ++count;
            continue;
        }

        switch (f) {
            case ROW:
                for(auto tu : row_v){
                    new_x = x + get<0>(tu);
                    new_y = y + get<1>(tu);

                    if(new_x < N && new_y < N && arr[new_x][new_y] == 0){
                        if(get<2>(tu) == DIA && (arr[new_x-1][new_y] == 1 || arr[new_x][new_y-1])){
                            continue;
                        }
                        q.push({new_x, new_y, get<2>(tu)});
                    }
                }
                break;
            case DIA:
                for(auto tu : dia_v){
                    new_x = x + get<0>(tu);
                    new_y = y + get<1>(tu);

                    if(new_x < N && new_y < N && arr[new_x][new_y] == 0){
                        if(get<2>(tu) == DIA && (arr[new_x-1][new_y] == 1 || arr[new_x][new_y-1])){
                            continue;
                        }
                        q.push({new_x, new_y, get<2>(tu)});
                    }
                }
                break;
            case COL:
                for(auto tu : col_v){
                    new_x = x + get<0>(tu);
                    new_y = y + get<1>(tu);

                    if(new_x < N && new_y < N && arr[new_x][new_y] == 0){
                        if(get<2>(tu) == DIA && (arr[new_x-1][new_y] == 1 || arr[new_x][new_y-1])){
                            continue;
                        }
                        q.push({new_x, new_y, get<2>(tu)});
                    }
                }
                break;
        }
    }

    cout << count << endl;

    return;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> arr[i][j];
        }
    }

    bfs();

    return 0;
}
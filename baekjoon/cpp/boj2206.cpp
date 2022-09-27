#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int visited[1001][1001][2];
vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<string>& v){
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    visited[0][0][1] = 1;

    int now_x, now_y, next_x, next_y, breakable;
    while(!q.empty()){
        tie(now_x, now_y, breakable) = q.front();
        q.pop();

        if(now_x == N-1 && now_y == M-1){
            return visited[now_x][now_y][breakable];
        }

        for(pair<int, int> adder : adders){
            next_x = now_x + adder.first;
            next_y = now_y + adder.second;

            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
                if(v[next_x][next_y] == '1' && breakable == 1){
                    visited[next_x][next_y][0] = visited[now_x][now_y][1] + 1;
                    q.push({next_x, next_y, 0});
                }
                else if(v[next_x][next_y] == '0' && visited[next_x][next_y][breakable] == 0){
                    visited[next_x][next_y][breakable] = visited[now_x][now_y][breakable] + 1;
                    q.push({next_x, next_y, breakable});
                }
            }
        }
    }

    return -1;
}

int main(void){
    cin >> N >> M;
    vector<string> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    cout << bfs(v) << endl;

    return 0;
}
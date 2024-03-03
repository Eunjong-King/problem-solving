/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <cmath>

using namespace std;

vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct BFS {
    int x;
    int y;
    int previous_direction;
    int cost;
};


int main()
{
    int N;
    cin >> N;
    
    vector<vector<char>> v(N, vector<char>(N));
    
    int start_x=-1, start_y=-1, end_x=-1, end_y=-1;
    for(int i=0; i<N; i++) {
        string inp;
        cin >> inp;
        
        for(int j=0; j<N; j++) {
            v[i][j] = inp[j];
            
            if(inp[j] == '#') {
                if(start_x == -1){
                    start_x = i;
                    start_y = j;
                } else{
                    end_x = i;
                    end_y = j;
                }
            }
        }
    }
    
    queue<BFS> q;
    vector<vector<vector<int>>> costs(N, vector<vector<int>>(N, vector<int>(4, 1e9)));
    
    for(int d=0; d<4; d++) {
        int new_x = start_x + directions[d].first;
        int new_y = start_y + directions[d].second;
        
        if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && v[new_x][new_y] != '*') {
            q.push({new_x, new_y, d, 0});
            costs[new_x][new_y][d] = 0;
        }
    }
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int pd = q.front().previous_direction;
        int cost = q.front().cost;

        q.pop();
        
        if(v[x][y] == '#') continue; // 주의
        if(v[x][y] == '.') {
            int new_x = x + directions[pd].first;
            int new_y = y + directions[pd].second;
            
            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && v[new_x][new_y] != '*') {
                if(costs[new_x][new_y][pd] <= cost) continue;
                
                q.push({new_x, new_y, pd, cost});
                costs[new_x][new_y][pd] = cost;
            }
            
            continue;
        }
        if(v[x][y] == '!') {
            for(int d=0; d<4; d++) {
                // 온 방향으로 되돌아가는 경우
                if(abs(d-pd) == 2) continue;
                
                int new_x = x + directions[d].first;
                int new_y = y + directions[d].second;
                int new_cost = d==pd ? cost : cost+1;
                
                if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && v[new_x][new_y] != '*') {
                    if(costs[new_x][new_y][d] <= new_cost) continue;
                    
                    q.push({new_x, new_y, d, new_cost});
                    costs[new_x][new_y][d] = new_cost;
                }
            }
        }
    }
    
    
    int result = 1e9;
    for(int d=0; d<4; d++) {
        result = min(costs[end_x][end_y][d], result);
    }
    cout << result << endl;
    
    return 0;
}
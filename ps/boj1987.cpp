#include <iostream>
#include <vector>
#include <array>
using namespace std;

int max_count = 1, R, C;
array<array<char, 20>, 20> arr;
vector<pair<int, int>> adders = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[26];

void recursive(int depth, int x, int y){
    if(max_count < depth){
        max_count = depth;
    }

    for(pair<int, int> p : adders){
        int new_x = x+p.first;
        int new_y = y+p.second;

        if(new_x >= 0 && new_x < R && new_y >= 0 && new_y < C){
            if(!visited[arr[new_x][new_y] - 'A']){
                visited[arr[new_x][new_y] - 'A'] = true;
                recursive(depth+1, new_x, new_y);
                visited[arr[new_x][new_y] - 'A'] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = true;
    recursive(1, 0, 0);

    cout << max_count << endl;

    return 0;
}
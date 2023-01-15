#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<vector<bool>> vvb;

int W, H;
vector<pair<int, int>> adder = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
vvb v;

void dfs(int i, int j){
    v[i][j] = false;

    for(pair<int, int> p : adder){
        int ni = i + p.first;
        int nj = j + p.second;


        if(ni < H && ni >= 0 && nj < W && nj >= 0 && v[ni][nj]){
            dfs(ni, nj);
        }
    }
}

int main(){
    while(true){
        cin >> W >> H;
        if(W == 0 && H == 0){
            break;
        }

        v = vvb(H, vector<bool>(W));

        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++){
                bool b;
                cin >> b;
                v[i][j] = b;
            }
        }

        int answer = 0;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(v[i][j]){
                    answer++;
                    dfs(i, j);
                }
            }
        }
        cout << answer << endl;
    }
}
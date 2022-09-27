#include <iostream>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int ** arr = NULL;
vector<pair<int, int>> vall{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> vup{{-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> vright{{1, 0}, {-1, 0}, {0, 1}};
vector<pair<int, int>> vdown{{1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> vleft{{1, 0}, {-1, 0}, {0, -1}};
map<pair<int, int>, int> m{{{1, 0}, 3}, {{-1, 0}, 1}, {{0, 1}, 2}, {{0, -1}, 4}};
int max_weight = 0;
int N, M;

// 0 아무대나 1 위 2 오 3 아래 4 왼
void dfs(pair<int, int> p, int depth, int direct, int weight){
    if(depth == 4){
        if(weight > max_weight){
            max_weight = weight;
        }
        return;
    }

    int i = p.first;
    int j = p.second;
    int nexti, nextj;

    if(direct == 0){
        for(auto temp : vall){
            nexti = i + temp.first;
            nextj = j + temp.second;

            if(nexti >= 0 && nexti < N && nextj >= 0 && nextj < M){
                dfs({nexti, nextj}, depth+1, m[{temp.first, temp.second}], weight+arr[nexti][nextj]);
            }
        }
    }
    else if(direct == 1){
        for(auto temp : vup){
            nexti = i + temp.first;
            nextj = j + temp.second;

            if(nexti >= 0 && nexti < N && nextj >= 0 && nextj < M){
                dfs({nexti, nextj}, depth+1, m[{temp.first, temp.second}], weight+arr[nexti][nextj]);
            }
        }
    }
    else if(direct == 2){
        for(auto temp : vright){
            nexti = i + temp.first;
            nextj = j + temp.second;

            if(nexti >= 0 && nexti < N && nextj >= 0 && nextj < M){
                dfs({nexti, nextj}, depth+1, m[{temp.first, temp.second}], weight+arr[nexti][nextj]);
            }
        }
    }
    else if(direct == 3){
        for(auto temp : vdown){
            nexti = i + temp.first;
            nextj = j + temp.second;

            if(nexti >= 0 && nexti < N && nextj >= 0 && nextj < M){
                dfs({nexti, nextj}, depth+1, m[{temp.first, temp.second}], weight+arr[nexti][nextj]);
            }
        }
    }
    else{
        for(auto temp : vleft){
            nexti = i + temp.first;
            nextj = j + temp.second;

            if(nexti >= 0 && nexti < N && nextj >= 0 && nextj < M){
                dfs({nexti, nextj}, depth+1, m[{temp.first, temp.second}], weight+arr[nexti][nextj]);
            }
        }
    }
}

int main(void){
    cin >> N >> M;

    arr = new int*[N];
    for(int i=0; i<N; i++){
        arr[i] = new int[M];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dfs({i, j}, 1, 0, arr[i][j]);
        }
    }
    
    int temp = 0;
    for(int i=0; i<(N-1); i++){
        for(int j=0; j<(M-2); j++){
            temp += arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
            if(max_weight < temp){
                max_weight = temp;
            }
            temp = 0;

            temp += arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
            if(max_weight < temp){
                max_weight = temp;
            }
            temp = 0;
        }
    }

    for(int i=0; i<(N-2); i++){
        for(int j=0; j<(M-1); j++){
            temp += arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
            if(max_weight < temp){
                max_weight = temp;
            }
            temp = 0;

            temp += arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i+1][j];
            if(max_weight < temp){
                max_weight = temp;
            }
            temp = 0;
        }
    }

    cout << max_weight << endl;

    for(int i=0; i<N; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
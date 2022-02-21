#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int arr[101][101];
    set<int> s;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }
    }

    int area, max_area=0, ti, tj, tti, ttj;
    int filter[101][101];
    queue<pair<int, int>> q;
    vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int height=0; height<102; height++){
        area=0;
        memset(filter, 0, sizeof(filter));
        q = queue<pair<int, int>>();

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j] > height && filter[i][j] == 0){
                    q.push({i, j});
                    filter[i][j] = 1;
                    area++;
                }
                while(!q.empty()){
                    ti = q.front().first;
                    tj = q.front().second;
                    q.pop(); 

                    for(auto adder : adders){
                        tti = ti + adder.first;
                        ttj = tj + adder.second;
                        if(tti >= 0 && tti < N && ttj >= 0 && ttj < N && filter[tti][ttj] == 0 && arr[tti][ttj] > height){
                            q.push({tti, ttj});
                            filter[tti][ttj] = 1;
                        }
                    }
                }
            }
        }
        if(area > max_area){
            max_area = area;
        }
    }

    cout << max_area << endl;
    return 0;
}
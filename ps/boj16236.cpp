#include <queue>
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int** arr = new int*[N];
    for(int i=0; i<N; i++){
        arr[i] = new int[N];
    }

    queue<tuple<int, int, int>> q;
    set<pair<int, int>> s;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 9){
                q.push({i, j, 0});
                s.insert({i, j});
                arr[i][j] = 0;
            }
        }
    }

    bool breaker = true;
    int i, j, ti, tj, sec;
    int size = 2;
    int ate = 0;
    int totalTime = 0;
    vector<pair<int, int>> v{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(breaker){
        int minSec = 410;
        vector<pair<int, int>> foods;
        while(!q.empty()){
            tie(i, j, sec) = q.front();
            q.pop();

            if(sec > minSec){
                continue;
            }

            for(pair<int, int> p : v){
                ti = i + p.first;
                tj = j + p.second;

                if(ti >= 0 && ti < N && tj >= 0 && tj < N){
                    if((arr[ti][tj] <= size) && (s.find({ti, tj}) == s.end())){
                        if(arr[ti][tj] == size || arr[ti][tj] == 0){
                            q.push({ti, tj, sec+1});
                        }
                        else if(arr[ti][tj] < size){
                            if(minSec > sec){
                                minSec = sec;
                                totalTime += (sec + 1);
                            }
                            foods.push_back({ti, tj});
                        }
                        s.insert({ti, tj});
                    }
                }
            }
        }
        if(foods.size() == 0){
            breaker = false;
        }
        else{
            sort(foods.begin(), foods.end());
            q = queue<tuple<int, int, int>>();
            s = set<pair<int, int>>();
            q.push({foods[0].first, foods[0].second, 0});
            s.insert({foods[0].first, foods[0].second});
            arr[foods[0].first][foods[0].second] = 0;

            ate++;
            if(size == ate){
                size++;
                ate = 0;
            }
        }
    }

    cout << totalTime << endl;

    for(int i=0; i<N; i++){
        delete[] arr[i];        
    }
    delete[] arr;
}
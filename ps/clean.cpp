#include <iostream>
#include <map>
#include <vector>
#include <array>
using namespace std;

int main(void){
    int N, from, to, cost;
    map<int, vector<pair<int, int>>> m;
    array<pair<int, int>, 1100> arr;
    arr[0] = {0, 0};

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> from >> to >> cost;
        m[to].push_back({cost, to-from+1});
    }


    int now_cost, new_cost;
    for(int i=1; i<=(365*3); i++){
        arr[i] = arr[i-1];
        if(m.count(i) != 0){
            for(auto mp : m[i]){
                now_cost = arr[i].first;
                if(arr[i-mp.second].second == 0){
                    new_cost = mp.first;
                }
                else{
                    new_cost = arr[i-mp.second].first + mp.first - 10;
                }

                if(new_cost > now_cost){
                    arr[i].first = new_cost;
                    arr[i].second = arr[i-mp.second].second + mp.second;
                }
                else if (new_cost == now_cost){
                    arr[i].second = min(arr[i].second, arr[i-mp.second].second + mp.second);
                }
            }
        }
    }

    cout << arr[1095].first << ' ' << arr[1095].second << endl;

    return 0;
}
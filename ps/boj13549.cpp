#include <queue>
#include <iostream>
using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    queue<pair<int, int>> q;
    int arr[100100];
    fill_n(arr, 100100, 100100);

    q.push({N, 0});
    
    int pos, count, min_count=100100;
    while(!q.empty()){
        pos = q.front().first;
        count = q.front().second;
        q.pop();

        if(pos==K && min_count>count){
            min_count = count;
        }

        if(min_count <= count){
            continue;
        }

        if(arr[pos] <= count){
            continue;
        }
        else if(arr[pos] > count){
            arr[pos] = count;
        }

        if(pos-1 >= 0){
            q.push({pos-1, count+1});
        }
        if(pos+1 <= 100000){
            q.push({pos+1, count+1});
        }
        if(pos*2 <= 100000){
            q.push({pos*2, count});
        }
    }

    cout << min_count << endl;

    return 0;
}
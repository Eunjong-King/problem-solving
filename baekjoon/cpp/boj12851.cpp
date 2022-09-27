#include <queue>
#include <iostream>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    int arr[100010];
    for(int i=0; i<100010; i++){
        arr[i] = 100010;
    }
   
    queue<pair<int, int>> q;
    q.push({N, 0});
   
    int pos, count, min_count=100010, result=0;
    while(!q.empty()){
        pos = q.front().first;
        count = q.front().second;
        q.pop();

        if(arr[pos] < count){
            continue;
        }
        else if(arr[pos] > count){
            arr[pos] = count;
        }
       
        if(min_count < count){
            break;
        }

        if(pos == K && min_count == 100010){
            result++;
            min_count = count;
        }
        else if(pos == K){
            result++;
        }
       
        if(pos-1 >= 0){
            q.push({pos-1, count+1});
        }
        if(pos+1 <= 100000){
            q.push({pos+1, count+1});
        }
        if(pos*2 <= 100000){
            q.push({pos*2, count+1});
        }
    }

    cout << min_count << '\n' << result << '\n';

    return 0;
}
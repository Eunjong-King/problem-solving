#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> num(N+1);
    vector<int> in(N+1);

    for(int i=1; i<=N; i++) {
        cin >> in[i];
        num[i] = i;
    }

    int target = 1;
    cout << 1 << ' ';
    num[1] = -1;
    int adder;
    for(int i=0; i<N-1; i++){
        adder = in[target];
        int diff = adder>0 ? 1 : -1;

        while(adder != 0){
            target += diff;

            if(target > N){
                target = 1;
            } else if(target < 1){
                target = N;
            }

            if(num[target] != -1){
                adder += (diff * -1);
            }
        }

        cout << target << " ";
        num[target] = -1;
    }
}
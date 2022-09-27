#include <iostream>
#include <cmath>
using namespace std;

long long T, x, y;

void solve(){
    long long difference = y - x;
    long long num, squared;
    num = sqrt(difference) - 1;
    if(num < 1){
        num = 1;
    }
    while(true){
        squared = num * num;
        if(squared-(num-1) <= difference && difference <= squared){
            cout << 2*num-1 << "\n";
            break;
        }
        else if(squared+1 <= difference && difference <= squared+num){
            cout << 2*num << "\n";
            break;
        }
        ++num;
        if(squared < 0){
            break;
        }
    }
    return;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        cin >> x >> y;
        solve();
    }

    return 0;
}
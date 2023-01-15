#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++){
        int inp;
        cin >> inp;
        v[i] = inp;
    }
    cin >> M;

    sort(v.begin(), v.end());

    int NewN = N;
    bool breaker = false;
    for(int i=0; i<NewN; i++){
        if(v[i] <= (M/N)){
            M -= v[i];
            N--;
        } else {
            int answer = M/N;
            cout << answer << endl;
            breaker = true;
            break;
        }
    }

    if(!breaker) {
        cout << v[NewN-1];
    }

    return 0;
}
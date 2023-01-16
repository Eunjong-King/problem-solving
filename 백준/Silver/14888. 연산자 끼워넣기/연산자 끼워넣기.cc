#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, MAX=-2000000000, MIN=2000000000;
vector<int> v;
vector<int> op;
vector<int> op_count;

void calc(){
    int result = v[0];
    for(int i=0; i<N-1; i++){
        if(op[i] == 0){
            result += v[i+1];
        } else if(op[i] == 1){
            result -= v[i+1];
        } else if(op[i] == 2){
            result *= v[i+1];
        } else {
            result /= v[i+1];
        }
    }

    if(result > MAX) {
        MAX = result;
    }
    if(result < MIN) {
        MIN = result;
    }
}

void f(int n){
    if(n == 0){
        calc();
        return;
    }
    for(int i=0; i<4; i++){
        if(op_count[i] > 0){
            op[N-n-1] = i;
            op_count[i]--;
            f(n-1);
            op_count[i]++;
        }
    }
}

int main() {
    cin >> N;

    v = vector<int>(N);
    op = vector<int>(N-1);

    for(int i=0; i<N; i++){
        int inp;
        cin >> inp;
        v[i] = inp;
    }

    op_count = vector<int>(4);
    for(int i=0; i<4; i++){
        int inp;
        cin >> inp;
        op_count[i] = inp;
    }

    f(N-1);

    cout << MAX << '\n' << MIN << '\n';

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

void print_binary(int i){
    stack<int> s;

    while(i != 0 && i != 1){
        s.push(i%2);
        i /= 2;
    }
    s.push(i);

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return;
}

int main(void){
    int N;
    cin >> N;

    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << "01";
    if(N == 1){
        cout << endl;
        return 0;
    }
    for(int i=2; i<=N; i++){
        print_binary(i);
    }

    cout << endl;

    return 0;
}
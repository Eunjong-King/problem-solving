#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, inp;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> inp;
        pq.push(inp);
    }

    int count = 0;
    int card1, card2, sum;
    while(pq.size() > 1){
        card1 = pq.top();
        pq.pop();
        card2 = pq.top();
        pq.pop();

        sum = card1 + card2;
        count += sum;
        pq.push(sum);
    }

    cout << count << endl;

    return 0;
}
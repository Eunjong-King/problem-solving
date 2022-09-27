#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    vector<int> v(1000001);
    queue<int> q;

    int target;
    cin >> target;

    int num = 1;
    q.push(num);
    v[num] = num;

    while(!q.empty()) {
        num = q.front();
        q.pop();

        if(target < num){
            continue;
        }
        else if(target == num){
            break;
        }

        if(num+1 <= 1000000 && v[num+1] == 0){
            v[num+1] = num;
            q.push(num+1);
        }
        if(num*2 <= 1000000 && v[num*2] == 0){
            v[num*2] = num;
            q.push(num*2);
        }
        if(num*3 <= 1000000 && v[num*3] == 0) {
            v[num*3] = num;
            q.push(num*3);
        }
    }


    vector<int> answer;
    answer.push_back(target);

    while(target != 1){
        answer.push_back(v[target]);
        target = v[target];
    }

    cout << answer.size()-1 << endl;
    for(int i : answer){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
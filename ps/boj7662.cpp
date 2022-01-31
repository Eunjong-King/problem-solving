#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main(void){
    int T, n, k, p;
    char D;
    cin >> T;

    for (int i=0; i<T; i++){
        bool breaker = false;
        cin >> k;
        priority_queue<int> gpq;
        priority_queue<int, vector<int>, greater<int>> lpq;
        map<int, int> m;

        for(int j=0; j<k; j++){
            cin >> D >> n;
            
            if (D == 'I'){
                gpq.push(n);
                lpq.push(n);

                if (m.count(n) == 0){
                    m[n] = 1;
                }
                else{
                    m[n]++;
                }
            }
            else{
                if (n == 1){
                    while (true){
                        if (gpq.empty()){
                            lpq = priority_queue<int, vector<int>, greater<int>>();
                            break;
                        }
                        p = gpq.top();
                        gpq.pop();
                        if (m[p] >= 1){
                            m[p]--;
                            break;
                        }
                    }
                }
                else{
                    while (true){
                        if(lpq.empty()){
                            gpq = priority_queue<int>();
                            break;
                        }
                        p = lpq.top();
                        lpq.pop();
                        if(m[p] >= 1){
                            m[p]--;
                            break;
                        }
                    }
                }
            }
        }
        
        while(true){
            if (gpq.empty()){
                cout << "EMPTY" << endl;
                breaker = true;
                break;
            }
            p = gpq.top();
            gpq.pop();
            if (m[p] >= 1){
                cout << p << " ";
                break;
            }
        }
        
        if (breaker){
            continue;
        }

        while(true){
            p = lpq.top();
            lpq.pop();
            if(m[p] >= 1){
                cout << p << endl;
                break;
            }
        }
    }
}
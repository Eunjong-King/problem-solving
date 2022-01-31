#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(void){
    queue<pair<int, int>> q;
    set<int> s;
    int N, K;
    cin >> N >> K;

    if (N == K){
        cout << 0 << endl;
        return 0;
    }

    s.insert(N);
    q.push({N, 0});

    int now, ind, a, b, c;
    while(!q.empty()){
        now = q.front().first;
        ind = q.front().second;
        q.pop();

        a = now - 1;
        b = now + 1;
        c = now * 2;

        if ((s.find(a) == s.end()) && a >= 0){
            if (a == K){
                break;
            }
            s.insert(a);
            q.push({a, ind+1});
        }
        if ((s.find(b) == s.end()) && b <= 100000){
            if (b == K){
                break;
            }
            s.insert(b);
            q.push({b, ind+1});
        }
        if (c <= 100000 && (s.find(c) == s.end())){
            if (c == K){
                break;
            }
            s.insert(c);
            q.push({c, ind+1});
        }
    }
    cout << ind+1 << endl;
}
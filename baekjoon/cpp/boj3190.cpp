#include <iostream>
#include <deque>
#include <map>
#include <vector>
using namespace std;

int arr[102][102];
map<int, char> change_direct;
deque<pair<int, int>> body;
vector<pair<int, int>> direct{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int N, K, L, total_time=0, x=1, y=1;

void input(){
    int tx, ty, s;
    char c;

    cin >> N >> K;
    for(int i=0; i<K; i++){
        cin >> tx >> ty;
        arr[tx][ty] = 1;
    }

    cin >> L;
    for(int i=0; i<L; i++){
        cin >> s >> c;
        change_direct[s] = c;
    }

    return;
}

bool check_valid(){
    for(pair<int, int> p : body){
        if(p.first == x && p.second == y){
            return false;
        }
    }
    if(x == 0 || y == 0 || x > N || y > N){
        return false;
    }

    return true;
}

void solve(){
    int now_direct=0;
    bool is_valid = true;
    body.push_back({1, 1});

    while(true){
        x += direct[now_direct].first;
        y += direct[now_direct].second;
        ++total_time;

        if(change_direct.count(total_time) == 1){
            if(change_direct[total_time] == 'L'){
                now_direct = (now_direct+1)%4;
            }
            else{
                now_direct = (now_direct+3)%4;
            }
        }

        is_valid = check_valid();
        if(!is_valid){
            break;
        }

        body.push_back({x, y});
        if(arr[x][y] != 1) {
            body.pop_front();
        }
        else{
            arr[x][y] = 0;
        }
    }

    return;
}

int main(void){
    input();
    solve();

    cout << total_time << endl;

    return 0;
}
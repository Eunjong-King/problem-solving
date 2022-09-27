#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int M, result=10000000;
vector<pair<int, int>> c, h;

int getDistance(vector<pair<int, int>>& choice){
    int real_sum = 0;
    for(pair<int, int>& p1 : h){
        int sum = 10000000;
        for(pair<int, int>& p2 : choice){
            sum = min(sum, (abs(p2.first-p1.first)+abs(p2.second-p1.second)));
        }
        real_sum += sum;
    }
    return real_sum;
}

void selectChicken(vector<pair<int, int>>& choice, int depth, int index){
    if(depth == M){
        result = min(result, getDistance(choice));
        return;
    }
    for(int i=index; i<c.size(); i++){
        choice.push_back(c[i]);
        selectChicken(choice, depth+1, i+1);
        choice.pop_back();
    }
}

int main(void){
    int N, inp;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> inp;
            if(inp == 1){
                h.push_back({i, j});
            }
            else if(inp == 2){
                c.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> temp;
    selectChicken(temp, 0, 0);
    cout << result << endl;

    return 0;
}
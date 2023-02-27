#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef vector<int> vi;

int N, M;

void solve(int problem, vi& v){
    int start = 0;
    int end = v.size()-1;
    int mid;

    while(start+1 < end){
        mid = (start + end) / 2;
        if(v[mid] > problem){
            end = mid;
        } else if (v[mid] == problem){
            cout << 1 << " ";
            return;
        } else {
            start = mid;
        }
    }

    if(v[start] == problem || v[end] == problem){
        cout << 1 << " ";
    } else {
        cout << 0 << " ";
    }
}

int main(){
    fastio;

    cin >> N;

    vi v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int problem;
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> problem;
        solve(problem, v);
    }

    return 0;
}
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    int arr[100100];
    fill_n(arr, 100100, 0);

    map<int, int> m;
    int W, V;
    for(int i=0; i<N; i++){
        scanf("%d %d", &W, &V);
        V = (arr[W] > V) ? arr[W] : V;

        if(V==0){
            continue;
        }
        
        arr[W] = V;
        m[W] = V;
    }
    
    int max_V = 0;
    for(int i=1; i<K+1; i++){
        if(arr[i] == 0){
            continue;
        }
        for(auto p : m){
            if(i+p.first <= K && (arr[i+p.first] < arr[i] + p.second)){
                arr[i+p.first] = arr[i] + p.second;
            }
        }
        if(arr[i] != 0 && arr[i] > max_V){
            max_V = arr[i];
        }
    }

    printf("%d\n", max_V);

    return 0;
}
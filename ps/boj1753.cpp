#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 2147483647
using namespace std;

vector<pair<int, int>> v[20003];
int* result;

void dijk(int& now){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, now});
    result[now] = 0;

    int weight, top;
    while(!pq.empty()){
        weight = pq.top().first;
        top = pq.top().second;
        pq.pop();

        for(pair<int, int> p : v[top]){
            if(result[p.first] > weight + p.second){
                result[p.first] = weight + p.second;
                pq.push({result[p.first], p.first});
            }
        }
    }
}

int main(void){
    int V, E, K;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    result = new int[V+2];
    for(int i=0; i<V+2; i++){
        result[i] = INF;
    }

    int a, b, c;
    for(int i=0; i<E; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }

    dijk(K);

    for(int i=1; i<V+1; i++){
        if(result[i] == INF){
            printf("INF\n");
        }
        else{
            printf("%d\n", result[i]);
        }
    }

    delete[] result;
    return 0;
}
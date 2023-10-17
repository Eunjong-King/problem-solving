#include <vector>
#include <climits>
#include <queue>
#include <iostream>
 
using namespace std;
 
int n, m, r, a, b, c;
int item[102] = {0, };
vector<pair<int, int>> v[102];
int dist[102] = {0, };
int ans = 0;
 
void dijkstra(int Start)
{
    int visited[102] = {0, };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }
    dist[Start] = 0;
    pq.push(make_pair(0, Start));
 
    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;
        pq.pop();
 
        if(!visited[x]){
            visited[x] = true;
            for(int i=0; i<v[x].size(); i++){
                if(dist[v[x][i].first]>cost+v[x][i].second){
                    dist[v[x][i].first] = cost+v[x][i].second;
                    pq.push(make_pair(dist[v[x][i].first], v[x][i].first));
                }
            }
        }
    }
}
 
void init()
{
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }
}
 
int main()
{
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++){
        cin>>item[i];
    }
    for(int i=0; i<r; i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
 
    for(int i=1; i<=n; i++){
        init();
        dijkstra(i);
        int total = 0;
        for(int j=1; j<=n; j++){
            if(dist[j]<=m) total += item[j];
        }
        ans = max(ans, total);
    }
    
    cout<<ans<<"\n";
    return 0;
}

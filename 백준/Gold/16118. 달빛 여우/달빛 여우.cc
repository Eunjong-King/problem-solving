/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct PQ {
    int node;
    bool is_now_run;
    int cost;
    
    bool operator < (const PQ& a) const {
        if(cost == a.cost) {
            return node < a.node;
        }
        return cost < a.cost;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> edges(N+1);
    
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    
    int dist[4001];
    fill(&dist[0], &dist[4001], 2e9);
    
    dist[1] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    
    while(!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        
        if(dist[now_node] < now_cost) continue;
        
        for(const pair<int, int>& a : edges[now_node]) {
            int next_node = a.first;
            int next_cost = now_cost + a.second * 2;
            
            if(next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }
    
    int dist2[4001][2];
    fill(&dist2[0][0], &dist2[4000][2], 2e9);
    
    priority_queue<PQ> pq2;
    pq2.push({1, true, 0});
    
    while(!pq2.empty()) {
        int now_node = pq2.top().node;
        bool is_now_run = pq2.top().is_now_run;
        int now_cost = -pq2.top().cost;
        pq2.pop();
        
        if(dist2[now_node][!is_now_run] < now_cost) continue;
        
        for(const pair<int, int>& a : edges[now_node]) {
            int next_node = a.first;
            int next_cost = now_cost + (is_now_run ? a.second : a.second * 4);
            
            if(next_cost < dist2[next_node][is_now_run]) {
                dist2[next_node][is_now_run] = next_cost;
                pq2.push({next_node, !is_now_run, -next_cost});
            }
        }
    }
    
    int result = 0;
    for(int i=2; i<=N; i++) {
        if(dist[i] < min(dist2[i][0], dist2[i][1])) {
            result++;
        }
        // cout << dist[i] << " vs (" << dist2[i][0] << ", " << dist2[i][1] << ")" << endl;
    }
    cout << result << endl;

    return 0;
}

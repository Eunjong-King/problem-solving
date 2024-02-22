#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, vector<pair<int, int>>> m;
vector<bool> visited(100002, false);

int max_distance = 0;

int dfs(int now, int cost) {
    int max_cost = cost;
    vector<int> costs;

    visited[now] = true;

    for(auto a : m[now]) {
        if(!visited[a.first]){
            visited[a.first] = true;

            int c = dfs(a.first, cost+a.second);
            if(c > max_cost) max_cost = c;

            costs.push_back(c-cost);

            visited[a.first] = false;
        }
    }

    if(costs.size() > 1) {
        sort(costs.rbegin(), costs.rend());

        if(max_distance < costs[0] + costs[1]) {
            max_distance = costs[0] + costs[1];
        }
    }

    if(max_distance < max_cost) {
        max_distance = max_cost;
    }

    return max_cost;
}

int main() {
    int V;
    cin >> V;


    for(int i=1; i<V; i++) {
        int start, to, cost;
        cin >> start >> to >> cost;

        m[start].push_back({to, cost});
        m[to].push_back({start, cost});
    }

    dfs(1, 0);

    cout << max_distance << '\n';

    return 0;
}
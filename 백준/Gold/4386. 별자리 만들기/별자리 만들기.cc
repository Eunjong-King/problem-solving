#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[100001];

int find_parent(int a) {
    if(a == parent[a]) {
        return a;
    }

    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    parent[b] = a;
}

bool is_same_parent(int a, int b) {
    return find_parent(a) == find_parent(b);
}

int main() {
    int N;
    cin >> N;

    vector<pair<double, double>> temp(N);
    vector<pair<double, pair<double, double>>> v;

    double v1, v2;
    for(int i=0; i<N; i++) {
        cin >> v1 >> v2;

        temp[i] = {v1, v2};
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == j) continue;

            v.push_back({sqrt(pow(temp[i].first - temp[j].first, 2) + pow(temp[i].second - temp[j].second, 2)), {i, j}});
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }

    double total = 0;
    for(auto a : v) {
        if(is_same_parent(a.second.first, a.second.second)) {
            continue;
        }

        total += a.first;

        union_parent(a.second.first, a.second.second);
    }
    cout.precision(3);
    cout << total << endl;

    return 0;
}
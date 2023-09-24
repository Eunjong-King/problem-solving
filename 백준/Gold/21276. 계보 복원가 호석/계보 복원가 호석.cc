#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    map<string, int> topo;
    string inp;
    map<string, vector<string>> child;
    for (int i = 0; i < N; ++i) {
        cin >> inp;

        topo[inp] = 0;
        child[inp] = {};
    }

    int M;
    cin >> M;

    string a, b;
    map<string, vector<string>> m;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        topo[a]++;
        m[b].push_back(a);
    }

    queue<string> q;
    vector<string> root;
    for (auto a: topo) {
        if (a.second == 0) {
            root.push_back(a.first);
            q.push(a.first);
        }
    }

    while (!q.empty()) {
        string f = q.front();

        for (string s: m[f]) {
            topo[s]--;

            if (topo[s] == 0) {
                child[f].push_back(s);
                q.push(s);
            }
        }

        q.pop();
    }

    sort(root.begin(), root.end());
    cout << root.size() << '\n';
    for (auto a: root) {
        cout << a << ' ';
    }
    cout << endl;
    for (auto a: child) {
        cout << a.first << ' ' << a.second.size() << ' ';

        vector<string> temp = a.second;
        sort(temp.begin(), temp.end());

        for (auto b: temp) {
            cout << b << ' ';
        }
        cout << endl;
    }

    return 0;
}
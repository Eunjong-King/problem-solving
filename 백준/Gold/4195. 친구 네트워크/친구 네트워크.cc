#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, string> parent;
map<string, int> num;

string find_parent(string a) {
    if (a == parent[a]) {
        return a;
    }

    string result = find_parent(parent[a]);
    parent[a] = result;
    return result;
}

int union_parent(string &a, string &b) {
    string irep = find_parent(a);
    string jrep = find_parent(b);

    if (irep == jrep) {
        return num[irep];
    }

    parent[irep] = jrep;
    num[jrep] += num[irep];

    return num[jrep];
}

bool is_same_parent(string ori, string diff) {
    string jrep = find_parent(diff);

    return ori == jrep;
}


int main() {
    FAST_IO;

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int F;
        cin >> F;

        string a, b;
        for (int j = 0; j < F; ++j) {
            cin >> a >> b;

            if (parent[a] == "") {
                parent[a] = a;
                num[a] = 1;
            }
            if (parent[b] == "") {
                parent[b] = b;
                num[b] = 1;
            }

            cout << union_parent(a, b) << '\n';
        }

        parent = map<string, string>();
        num = map<string, int>();
    }
    return 0;
}
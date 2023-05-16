#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int c, r;
int N;
vector<vector<int>> v(50);

int search(int parent) {
    if (parent == r) {
        return -1;
    }

    if (v[parent].empty()) {
        c++;
        return 0;
    }

    for (int node: v[parent]) {
        int ret = search(node);

        if (ret == -1 && v[parent].size() == 1) {
            c++;
        }
    }

    return 0;
}

int main() {
    FAST_IO;

    cin >> N;

    int inp, head;
    for (int i = 0; i < N; ++i) {
        cin >> inp;

        if (inp == -1) head = i;
        else {
            v[inp].push_back(i);
        }
    }

    cin >> r;

    search(head);

    cout << c << '\n';

    return 0;
}
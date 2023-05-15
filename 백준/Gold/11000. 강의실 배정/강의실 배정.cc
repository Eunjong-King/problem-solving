#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    vector<pair<int, int>> v(N * 2);

    int from, to;
    for (int i = 0; i < N; ++i) {
        cin >> from >> to;

        v[i * 2] = {from, 1};
        v[i * 2 + 1] = {to, -1};
    }

    sort(v.begin(), v.end());

    int before = v[0].first;
    int sum = 0;
    int max_sum = 0;
    for (pair<int, int> &p: v) {
        sum += p.second;

        if (before != p.first && sum > max_sum) {
            max_sum = sum;
        }
    }

    cout << max_sum << '\n';

    return 0;
}
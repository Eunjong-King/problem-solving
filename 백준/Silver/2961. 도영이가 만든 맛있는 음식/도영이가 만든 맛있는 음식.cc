#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    int x, y;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        v[i] = {x, y};
    }

    int answer = INT_MAX;
    for (int i = 1; i < (1 << N); ++i) {
        int a = 1, b = 0;

        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                a *= v[j].first;
                b += v[j].second;
            }
        }

        answer = min(answer, abs(a - b));
    }

    cout << answer << endl;

    return 0;
}
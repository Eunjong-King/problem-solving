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

    vi v(N);
    vi dp1(N);
    vi dp2(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < N; ++i) {
        dp1[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        dp2[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < N; ++i) {
        max_len = max(max_len, dp1[i] + dp2[N - 1 - i]);
    }

    cout << max_len - 1 << '\n';

    return 0;
}
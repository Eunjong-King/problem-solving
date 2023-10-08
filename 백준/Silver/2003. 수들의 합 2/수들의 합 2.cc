#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N, M;
    cin >> N >> M;

    vector<int> sum(N + 1);
    sum[0] = 0;

    int inp;
    for (int i = 1; i <= N; ++i) {
        cin >> inp;

        sum[i] = sum[i - 1] + inp;
    }

    int result = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sum[i] - sum[j] == M) {
                result++;
            }
        }
    }

    cout << result << '\n';

    return 0;
}
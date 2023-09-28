#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vi v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int M, inp;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            cin >> inp;

            cout << binary_search(v.begin(), v.end(), inp) << '\n';
        }
    }

    return 0;
}
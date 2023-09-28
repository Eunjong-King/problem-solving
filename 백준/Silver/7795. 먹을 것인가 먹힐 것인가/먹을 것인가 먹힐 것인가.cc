#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vi A(N), B(M);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        sort(B.begin(), B.end());

        int count = 0;
        for (int a: A) {
            int start = 0, end = M - 1;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (a <= B[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            count += start;
        }
        cout << count << endl;
    }

    return 0;
}
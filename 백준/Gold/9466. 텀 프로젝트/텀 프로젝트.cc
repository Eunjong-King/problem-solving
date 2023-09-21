#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vi v(n + 1, 2);
        vi state(n + 1, 2);

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];

            if (v[i] == i) {
                state[i] = 1;
            }
        }

        // 0 -> ㅇㅏ님     1 -> 맞음     2-> 모름     3-> 지금하는중
        for (int i = 1; i <= n; ++i) {
            if (state[i] == 2) {
                int idx = i;
                int start = 0;

                while (true) {
                    state[idx] = 3;
                    idx = v[idx];

                    if (state[idx] == 0 || state[idx] == 1) {
                        break;
                    } else if (state[idx] == 2) {
                        continue;
                    } else {
                        start = idx;
                        break;
                    }
                }

                int marker = 0;
                idx = i;
                while (true) {
                    if (state[idx] != 3) {
                        break;
                    }

                    if (idx == start) {
                        marker = 1;
                    }

                    state[idx] = marker;

                    idx = v[idx];
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (state[i] == 0) {
                result++;
            }
        }
        cout << result << '\n';
    }


    return 0;
}
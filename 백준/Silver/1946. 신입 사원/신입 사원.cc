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
        int N;
        cin >> N;

        vector<pair<int, int>> v(N);

        int a, b;
        for (int i = 0; i < N; ++i) {
            cin >> a >> b;
            v[i] = {a, b};
        }

        std::sort(v.begin(), v.end());

        int count = 1;
        int MIN = v[0].second;
        for (int i = 1; i < N; ++i) {
            if (v[i].second < MIN) {
                count++;
                MIN = v[i].second;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
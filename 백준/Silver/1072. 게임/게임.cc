#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
    FAST_IO;

    ll X, Y;
    cin >> X >> Y;

    ll rate = (Y * 100) / X;

    if (rate >= 99) {
        cout << -1 << endl;
        return 0;
    }

    ll start = 1, end = X;

    while (start <= end) {
        ll mid = (start + end) / 2;
        ll temp_rate = ((Y + mid) * 100) / (X + mid);

        if (temp_rate <= rate) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << start << endl;

    return 0;
}
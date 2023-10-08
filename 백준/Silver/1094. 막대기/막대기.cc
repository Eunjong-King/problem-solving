#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    bool bit[7];
    for (bool &i: bit) {
        i = false;
    }

    int X;
    cin >> X;

    int result = 0;
    for (int i = 6; i >= 0; --i) {
        if (pow(2, i) <= X) {
            result++;
            X -= (int) pow(2, i);
        }
    }

    cout << result << endl;

    return 0;
}
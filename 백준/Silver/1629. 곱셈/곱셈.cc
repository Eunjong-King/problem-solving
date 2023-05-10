#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int A, B, C;

ll power(int b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return A % C;
    }

    ll temp = power(b / 2) % C;
    if (b % 2 == 0) {
        return (temp * temp) % C;
    } else {
        return ((temp * temp) % C * A % C) % C;
    }
}

int main() {
    FAST_IO;

    cin >> A >> B >> C;

    cout << power(B) % C << '\n';

    return 0;
}
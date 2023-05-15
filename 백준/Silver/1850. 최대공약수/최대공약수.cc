#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>

using namespace std;
typedef long long ll;

ll BCD(ll A, ll B) {
    ll temp = A % B;

    if (temp == 0) {
        return B;
    }

    A = B;
    B = temp;

    return BCD(A, B);
}

int main() {
    FAST_IO;

    ll A, B;
    cin >> A >> B;

    if (A < B) swap(A, B);

    ll answer = BCD(A, B);
    for (int i = 0; i < answer; ++i) {
        cout << '1';
    }
    cout << '\n';

    return 0;
}
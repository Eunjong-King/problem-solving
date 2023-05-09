#include <iostream>

using namespace std;

void hanoi(int N, int from, int to, int sub) {
    if(N == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(N-1, from, sub, to);
    cout << from << ' ' << to << '\n';
    hanoi(N-1, sub, to, from);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << '\n';
    hanoi(N, 1, 3, 2);

    return 0;
}
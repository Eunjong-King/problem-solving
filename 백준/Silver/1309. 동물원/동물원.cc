#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    int prev_no = 1;
    int prev_yes = 2;
    int no;
    int yes;

    for (int i = 1; i < N; ++i) {
        no = (prev_no + prev_yes) % 9901;
        yes = (prev_no * 2 + prev_yes) % 9901;

        prev_no = no;
        prev_yes = yes;
    }

    cout << (prev_no + prev_yes) % 9901 << '\n';
    return 0;
}
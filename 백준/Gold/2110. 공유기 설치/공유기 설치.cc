#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int N, C;
    cin >> N >> C;

    vi house(N);

    for (int i = 0; i < N; ++i) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int left = 1;
    int right = house[N - 1] - house[0];
    int answer = 0;

    while (left <= right) {
        int router = 1;
        int mid = (left + right) / 2;
        int start = house[0];

        for (int i = 1; i < N; ++i) {
            if (house[i] - start >= mid) {
                router++;
                start = house[i];
            }
        }

        if (router >= C) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
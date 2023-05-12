#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
typedef vector<int> vi;

constexpr int MAX_N = 1000001;

int main() {
    FAST_IO;

    bool arr[MAX_N];
    memset(arr, true, MAX_N * sizeof(bool));
    arr[1] = false;

    for (int i = 1; i < MAX_N; ++i) {
        if (!arr[i]) {
            continue;
        }

        for (int j = i * 2; j < MAX_N; j += i) {
            arr[j] = false;
        }
    }

    while (true) {
        int inp;
        cin >> inp;

        if (inp == 0) {
            break;
        }

        bool isGoldbach = false;
        for (int i = 2; i <= inp / 2; ++i) {
            if (!arr[i]) {
                continue;
            }

            if (arr[inp - i]) {
                cout << inp << " = " << i << " + " << inp - i << '\n';
                isGoldbach = true;
                break;
            }
        }

        if (!isGoldbach) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
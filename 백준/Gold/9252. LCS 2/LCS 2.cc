#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;

int arr[1002][1002];

int main() {
    FAST_IO;

    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    int total_size = arr[a.size()][b.size()];
    cout << total_size << endl;

    vector<char> answer;
    int i = a.size(), j = b.size();
    while (arr[i][j] != 0) {
        if (arr[i][j - 1] == arr[i][j]) {
            j--;
        } else if (arr[i - 1][j] == arr[i][j]) {
            i--;
        } else {
            answer.push_back(a[i - 1]);
            i--;
            j--;
        }
    }

    reverse(answer.begin(), answer.end());

    for (char c: answer) {
        cout << c;
    }
    cout << endl;

    return 0;
}
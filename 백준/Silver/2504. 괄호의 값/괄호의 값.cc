#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

using namespace std;

int main() {
    FAST_IO;

    string str;
    cin >> str;

    stack<int> s;
    map<char, int> m{{'(', -1},
                     {')', -2},
                     {'[', -3},
                     {']', -4}};

    bool isValid = true;

    for (char c: str) {
        if (m[c] == -1 || m[c] == -3) {
            s.emplace(m[c]);
        } else {
            if (s.empty()) {
                isValid = false;
                break;
            }

            int sum = 0;
            while (!s.empty()) {
                if (s.top() < 0) {
                    break;
                }
                sum += s.top();
                s.pop();
            }

            if (s.empty()) {
                isValid = false;
                break;
            }

            if (s.top() == m['('] && c == ')') {
                sum = sum == 0 ? 2 : 2 * sum;
            } else if (s.top() == m['['] && c == ']') {
                sum = sum == 0 ? 3 : 3 * sum;
            } else {
                isValid = false;
                break;
            }

            s.pop();
            s.emplace(sum);
        }
    }

    if (!isValid) {
        cout << 0 << '\n';
        return 0;
    }

    int result = 0;
    while (!s.empty()) {
        if (s.top() < 0) {
            isValid = false;
            break;
        }

        result += s.top();
        s.pop();
    }

    if (isValid) {
        cout << result << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
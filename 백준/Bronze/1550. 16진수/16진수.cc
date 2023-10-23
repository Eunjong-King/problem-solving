#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vb> vvb;

int main() {
    FAST_IO;

    string inp;
    cin >> inp;

    int result = 0;
    for (int i = 0; i < inp.size(); ++i) {
        int temp = 0;

        if ('0' <= inp[i] && inp[i] <= '9') {
            temp = inp[i] - '0';
        } else {
            temp = inp[i] - 55;
        }

        result += temp * pow(16, inp.size() - i - 1);
    }
    cout << result << endl;

    return 0;
}
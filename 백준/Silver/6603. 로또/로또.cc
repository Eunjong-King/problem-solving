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

int K;
vi v;

void recursive(vi temp, int idx, int depth) {
    if (depth == 6) {
        for (int i: temp) {
            cout << i << ' ';
        }
        cout << endl;

        return;
    }

    for (int i = idx; i < K; ++i) {
        vi new_temp = temp;
        new_temp.pb(v[i]);

        recursive(new_temp, i + 1, depth + 1);
    }
}

int main() {
    FAST_IO;

    while (true) {
        cin >> K;

        if (K == 0) {
            break;
        }

        v = vi(K);
        for (int i = 0; i < K; ++i) {
            cin >> v[i];
        }

        recursive({}, 0, 0);

        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

#define FAST_IO                       \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

vvll multiple_matrix(const vvll& a, const vvll& b) {
    vvll ret(2, vll(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll sum = 0;

            for (int k = 0; k < 2; k++) {
                sum += a[i][k] * b[k][j];
            }

            ret[i][j] = sum % 1000000007;
        }
    }

    return ret;
}

int main() {
    FAST_IO

    ll N;
    cin >> N;

    bool exp_check[61] = {0};
    int exp = 60;
    ll num = pow(2, exp);

    while (N > 0) {
        if (N >= num) {
            N -= num;
            exp_check[exp] = true;
        }

        exp--;
        num /= 2;
    }

    vvll result(2, vll(2, 0));
    result[0][0] = 1;
    result[1][1] = 1;

    vvll exp_matrix(2, vll(2, 1));
    exp_matrix[1][1] = 0;

    if (exp_check[0]) {
        result = multiple_matrix(exp_matrix, result);
    }
    for (int i = 1; i < 61; i++) {
        exp_matrix = multiple_matrix(exp_matrix, exp_matrix);

        if (exp_check[i]) {
            result = multiple_matrix(result, exp_matrix);
        }
    }

    cout << result[0][1] << endl;

    return 0;
}
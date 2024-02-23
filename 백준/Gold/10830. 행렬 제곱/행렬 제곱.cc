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

int N;

vvi multiple_vector(const vvi &a, const vvi &b)
{
    vvi result(N, vi(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum % 1000;
        }
    }

    return result;
}

int main()
{
    FAST_IO

    ll B;
    cin >> N >> B;

    vvi v(N, vi(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<bool> vb(51, false);
    int exp = 50, max_exp = 0;
    ll num = pow(2, exp);

    while (B > 0)
    {
        if (B >= num)
        {
            vb[exp] = true;
            B -= num;

            if (max_exp < exp)
            {
                max_exp = exp;
            }
        }

        exp--;
        num /= 2;
    }

    vvi result(N, vi(N, 0));
    for (int i = 0; i < N; i++)
    {
        result[i][i] = 1;
    }

    if (vb[0])
    {
        result = multiple_vector(result, v);
    }
    for (int i = 1; i <= max_exp; i++)
    {
        v = multiple_vector(v, v);
        if (vb[i])
        {
            result = multiple_vector(result, v);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N, M;
    ll K, D, A, k, d, a;
    cin >> N;

    while(N--){
        ll sum = 0;
        cin >> M;
        vector<vector<ll>> v;
        while(M--){
            cin >> K >> D >> A;
            v.push_back({K, D, A});
        }

        cin >> k >> d >> a;

        for(vector<ll> v1 : v){
            ll temp_sum = v1[0] * k;
            temp_sum -= v1[1] * d;
            temp_sum += v1[2] * a;

            if (temp_sum > 0ll){
                sum += temp_sum;
            }
        }

        cout << sum << endl;
    }
}
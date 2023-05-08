#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    iota(v.begin(), v.end(), 1);

    cout << "<";
    int idx = 0;
    while(v.size() > 1) {
        idx += (K-1);
        if(idx >= v.size()) {
            idx %= v.size();
        }

        cout << v.at(idx) << ", ";
        v.erase(v.begin()+idx);
    }
    cout << v.at(0);
    cout << ">" << endl;

    return 0;
}
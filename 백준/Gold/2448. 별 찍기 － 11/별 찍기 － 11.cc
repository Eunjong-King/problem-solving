#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> v(1024*3*2-1, vector<char>(1024*3*2-1, ' '));
int N;

void recursive(int n, int x, int y) {
    if(n == 3) {
        v[x][y] = '*';
        v[x+1][y-1] = '*';
        v[x+1][y+1] = '*';
        v[x+2][y-2] = '*';
        v[x+2][y-1] = '*';
        v[x+2][y] = '*';
        v[x+2][y+1] = '*';
        v[x+2][y+2] = '*';

        return;
    }

    recursive(n/2, x, y);
    recursive(n/2, x+n/2, y-n/2);
    recursive(n/2, x+n/2, y+n/2);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    recursive(N, 0, N-1);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N*2-1; j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }

    return 0;
}
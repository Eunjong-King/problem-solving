#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<bool>> arr(N + 1, vector<bool>(N + 1, false));
        vector<int> inp(N);
        for (int i = 0; i < N; ++i) {
            cin >> inp[i];
        }

        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                arr[inp[i]][inp[j]] = true;
            }
        }

        int M;
        cin >> M;

        int a, b;
        for (int i = 0; i < M; ++i) {
            cin >> a >> b;

            if (arr[a][b]) {
                arr[a][b] = false;
                arr[b][a] = true;
            } else {
                arr[a][b] = true;
                arr[b][a] = false;
            }
        }

        vi indegree(N + 1, 0);
        map<int, vi> m;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (arr[i][j]) {
                    indegree[j]++;
                    m[i].push_back(j);
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vi answer;
        int state = 0;
        for (int i = 0; i < N; ++i) {
            if (q.empty()) {
                cout << "IMPOSSIBLE" << endl;
                state = 1;
                break;
            }

            int f = q.front();
            answer.push_back(f);

            bool isFirst = true;
            for (int elem: m[f]) {
                indegree[elem]--;

                if (indegree[elem] == 0) {
                    if (!isFirst) {
                        cout << "?" << endl;
                        state = 2;
                        i = N;
                        break;
                    }
                    isFirst = false;
                    q.push(elem);
                }
            }

            q.pop();
        }

        if (state == 0) {
            for (auto elem: answer) {
                cout << elem << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
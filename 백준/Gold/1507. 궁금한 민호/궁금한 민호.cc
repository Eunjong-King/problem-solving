/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> dist(N, vector<int>(N, 1e9));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> dist[i][j];
        }
    }
    
    bool isUnused[20][20] = { 0 };
    for(int mid=0; mid<N; mid++) {
        for(int from=0; from<N-1; from++) {
            for(int to=from+1; to<N; to++) {
                if(from == mid || mid == to) continue;
                
                if(dist[from][to] > dist[from][mid] + dist[mid][to]) {
                    cout << -1 << endl;
                    return 0;
                }
                
                if(dist[from][to] == dist[from][mid] + dist[mid][to]) {
                    isUnused[from][to] = true;
                }
            }
        }
    }
    
    int result = 0;
    for(int from=0; from<N-1; from++) {
        for(int to=from+1; to<N; to++) {
            if(!isUnused[from][to]) {
                result += dist[from][to];
            }
        }
    }
    cout <<result <<endl;

    return 0;
}

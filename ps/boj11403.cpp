#include <set>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;


int main(void){
    int N;
    cin >> N;

    char** c = NULL;
    c = new char* [N];
    char ** result = new char* [N];
    for(int i=0; i<N; i++){
        c[i] = new char[N];
        result[i] = new char[N];
    }

    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> c[i][j];
            result[i][j] = '0';
        }
    }
    
    for(int i=0; i<N; i++){
        queue<int> q;
        set<int> s;
        for(int j=0; j<N; j++){
            if (c[i][j] == '1'){
                q.push(j);
                s.insert(j);
            }
        }
        int temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            result[i][temp] = '1';
            for(int j=0; j<N; j++){
                if(c[temp][j] == '1'){
                    if(s.find(j) == s.end()){
                        q.push(j);
                        s.insert(j);
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    for(int i=0; i<N; i++){
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
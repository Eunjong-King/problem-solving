#include <iostream>
#include <string>
using namespace std;

void dfs(char** b, int fx, int tx, int fy, int ty){
    char first = b[fx][fy];
    if (tx-fx == 1){
        cout << first;
        return;
    }

    bool trigger = true;

    for(int i=fx; i<tx; i++){
        for(int j=fy; j<ty; j++){
            if (b[i][j] != first){
                trigger = false;
                int size = (tx - fx)/2;
                cout << '(';
                for(int x=0; x<2; x++){
                    for(int y=0; y<2; y++){
                        dfs(b, fx+size*x, fx+size+size*x, fy+size*y, fy+size+size*y);
                    }
                }
                cout << ')';
                goto L;
            }
        }
    }
    L:
    if(trigger){
        cout << first;
    }
}

int main(void){
    int N;
    cin >> N;


    char ** b = NULL;
    b = new char*[N];
    for(int i=0; i<N; i++){
        b[i] = new char[N];
    }

    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        for (int j=0; j<N; j++){
            b[i][j] = row[j];
        }
    }

    dfs(b, 0, N, 0, N); // 0 <= x < N
    cout << endl;
    for(int i=0; i<N; i++){
        delete[] b[i];
    }
    delete[] b;
}
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool check[10000];

int main(void){
    int T, A, B;
    cin >> T;

    vector<char> v{'D', 'S', 'L', 'R'};
    for(int i=0; i<T; i++){
        scanf("%d %d", &A, &B);

        queue<pair<int, string>> q;

        q.push({A, ""});
        check[A] = true;

        string fs, fss;
        int fi, fii;
        while(!q.empty()){
            fi = q.front().first;
            fs = q.front().second;
            q.pop();

            for(char c : v){
                fii = fi;
                fss = fs;
                if(c == 'D'){
                    fii = (fii * 2) % 10000;
                }
                else if(c == 'S'){
                    if(fii == 0){
                        fii = 9999;
                    }
                    else{
                        fii--;
                    }
                }
                else if(c == 'R'){
                    fii = fii / 10 + (fii % 10) * 1000;
                }
                else{
                    if(fii < 1000){
                        fii *= 10;
                    }
                    else{
                        fii = (fii * 10) % 10000 + (fii / 1000);
                    }
                }
                fss += c;
                if(!check[fii]){
                    check[fii] = true;
                    if(fii == B){
                        memset(check, false, sizeof(check));
                        cout << fss << endl;
                        goto L;
                    }
                    q.push({fii, fss});
                }
            }
        }
        L:
        continue;
    }
}
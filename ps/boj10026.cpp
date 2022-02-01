#include <string>
#include <queue>
#include <set>
#include <iostream>
using namespace std;

char ** c = NULL;
set<pair<int, int>> GRs;
set<pair<int, int>> Bs;
vector<pair<int, int>> adders{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N;

void bfs(int i, int j, char color, bool isGR){
    queue<pair<int, int>> q;

    q.push({i, j});

    int topi, topj, ni, nj;
    pair<int, int> temp;
    if(isGR){
        GRs.insert({i, j});
        if(color == 'G' || color == 'R'){
            while(!q.empty()){
                temp = q.front();
                topi = temp.first;
                topj = temp.second;
                q.pop();

                for(auto adder : adders){
                    ni = topi + adder.first;
                    nj = topj + adder.second;

                    if (ni >= 0 && ni < N && nj >= 0 && nj < N){
                        if(c[ni][nj] == 'G' || c[ni][nj] == 'R'){
                            if(GRs.find({ni, nj}) == GRs.end()){
                                q.push({ni, nj});
                                GRs.insert({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        else{
            while(!q.empty()){
                temp = q.front();
                topi = temp.first;
                topj = temp.second;
                q.pop();

                for(auto adder : adders){
                    ni = topi + adder.first;
                    nj = topj + adder.second;

                    if (ni >= 0 && ni < N && nj >= 0 && nj < N){
                        if(c[ni][nj] == color){
                            if(GRs.find({ni, nj}) == GRs.end()){
                                q.push({ni, nj});
                                GRs.insert({ni, nj});
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        Bs.insert({i, j});

        while(!q.empty()){
            temp = q.front();
            topi = temp.first;
            topj = temp.second;
            q.pop();

            for(auto adder : adders){
                ni = topi + adder.first;
                nj = topj + adder.second;

                if (ni >= 0 && ni < N && nj >= 0 && nj < N){
                    if(c[ni][nj] == color){
                        if(Bs.find({ni, nj}) == Bs.end()){
                            q.push({ni, nj});
                            Bs.insert({ni, nj});
                        }
                    }
                }
            }
        }
    }
}

int main(void){
    cin >> N;

    c = new char*[N];
    for(int i=0; i<N; i++){
        c[i] = new char[N];
    }

    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        for(int j=0; j<N; j++){
            c[i][j] = row[j];
        }
    }

    int GRcount = 0, Bcount = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(GRs.find({i, j}) == GRs.end()){
                bfs(i, j, c[i][j], true);
                GRcount++;
            }
            if(Bs.find({i, j}) == Bs.end()){
                bfs(i, j, c[i][j], false);
                Bcount++;
            }
        }
    }
    cout << Bcount << " " << GRcount << endl;

    for(int i=0; i<N; i++){
        delete[] c[i];
    }
    delete[] c;

    return 0;
}

#include <iostream>
using namespace std;

int N, M, x, y, d, mycount=0;
int arr[51][51];

void input(){
    cin >> N >> M;
    cin >> x >> y >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
}

void num1(){
    arr[x][y] = 2;
    ++mycount;

    return;
}

int num2(){
    int tempx=x, tempy=y;
    if((arr[x-1][y] == 1 || arr[x-1][y] == 2) && (arr[x+1][y] == 1 || arr[x+1][y] == 2) && (arr[x][y-1] == 1 || arr[x][y-1] == 2) && (arr[x][y+1] == 1 || arr[x][y+1] == 2)){
        if(d == 0){
            ++tempx;
        }
        else if(d == 1){
            --tempy;
        }
        else if(d == 2){
            --tempx;
        }
        else{
            ++tempy;
        }

        if(arr[tempx][tempy] != 1){
            x = tempx;
            y = tempy;

            return 0;
        }
        else{
            return 2;
        }
    }
    else{
        if(d==0){
            --tempy;
        }
        else if(d==1){
            --tempx;
        }
        else if(d==2){
            ++tempy;
        }
        else{
            ++tempx;
        }

        d = (d+3)%4;
        if(arr[tempx][tempy] == 0){
            x=tempx;
            y=tempy;
            return 1;
        }
        else{
            return 0;
        }
    }
}

void print(){
    cout << x << y << d << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve(){
    int checker = 1;
    while(true){
        if(checker == 1){
            num1();
        }
        checker = num2();

        if(checker == 2){
            break;
        }
    }

    return;
}

int main(void){
    input();
    solve();

    cout << mycount << endl;

    return 0;
}
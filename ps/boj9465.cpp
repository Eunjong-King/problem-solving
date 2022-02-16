#include <iostream>
using namespace std;

int main(void){
    int T, n;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        int** arr = new int*[2];
        for(int j=0; j<2; j++){
            arr[j] = new int[n];
        }

        for(int a=0; a<2; a++){
            for(int b=0; b<n; b++){
                cin >> arr[a][b];
            }
        }

        if(n==1){
            if(arr[0][0] > arr[1][0])
                cout << arr[0][0] << '\n';
            else
                cout << arr[1][0] << '\n';
        }
        else if(n==2){
            if(arr[0][0]+arr[1][1] > arr[0][1] + arr[1][0])
                cout << arr[0][0]+arr[1][1] << '\n';
            else
                cout << arr[0][1]+arr[1][0] << '\n';
        }
        else{
            arr[0][1] += arr[1][0];
            arr[1][1] += arr[0][0];
            for(int b=2; b<n; b++){
                arr[0][b] = ((arr[0][b] + arr[1][b-1]) > (arr[0][b] + arr[1][b-2])) ? (arr[0][b] + arr[1][b-1]) : (arr[0][b] + arr[1][b-2]);
                arr[1][b] = ((arr[1][b] + arr[0][b-1]) > (arr[1][b] + arr[0][b-2])) ? (arr[1][b] + arr[0][b-1]) : (arr[1][b] + arr[0][b-2]);
            }
            if(arr[0][n-1] > arr[1][n-1])
                cout << arr[0][n-1] << '\n';
            else
                cout << arr[1][n-1] << '\n';
        }

        for(int a=0; a<2; a++){
            delete[] arr[a];
        }
        delete[] arr;
    }

    return 0;
}
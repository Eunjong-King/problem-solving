#include <cstdio>
using namespace std;

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int** arr = new int*[N];
    for(int i=0; i<N; i++){
        arr[i] = new int[N];
    }

    int inp;
    for(int i=0; i<N; i++){
        int temp = 0;
        for(int j=0; j<N; j++){
            scanf("%d", &inp);
            temp += inp;
            arr[i][j] = temp;
        }
    }

    int a, b, c, d;
    for(int i=0; i<M; i++){
        int sum = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int j=a-1; j<c; j++){
            if(b==1){
                sum += arr[j][d-1];
            }
            else{
                sum += (arr[j][d-1] - arr[j][b-2]);
            }
        }
        printf("%d\n", sum);
    }

    for(int i=0; i<N; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
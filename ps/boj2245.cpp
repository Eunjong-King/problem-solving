#include <cstdio>
#define MAX 100002
using namespace std;

int main(void){
    int A[MAX] = {0, };
    int B[MAX] = {0, };
    int marker[MAX] = {0, };
    int N;
    scanf("%d", &N);

    int inp;
    for(int i=0; i<N; i++){
        scanf("%d", &inp);
        A[i] = inp;
    }
    for(int i=0; i<N; i++){
        scanf("%d", &inp);
        B[i] = inp;
    }

    for(int i=0; i<N; i++){
        if(marker[A[i]] == 0){
            
        }
    }

    return 0;
}
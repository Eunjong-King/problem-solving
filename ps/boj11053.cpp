#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int* input = new int[N];
    int* result = new int[N];
    for(int i=0; i<N; i++){
        cin >> input[i];
        result[i] = 1;
    }
    result[0] = 1;

    int max_result = 1;
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(input[i] > input[j]){
                if(result[j]+1 > result[i]){
                    result[i] = result[j]+1;
                    if(result[i] > max_result){
                        max_result = result[i];
                    }
                }
            }
        }
    }
    
    cout << max_result << endl;

    delete[] input;
    delete[] result;
    return 0;
}
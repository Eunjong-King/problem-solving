#include <set>
#include <string>
#include <iostream>
using namespace std;

char** c = NULL;

int main(void){
    int N;
    cin >> N;

    c = new char* [N];
    for(int i=0; i<N; i++){
        c[i] = new char[N];
    }

    string temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        for (int j=0; j<N; j++){

        }
    }

    for(int i=0; i<N; i++){
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
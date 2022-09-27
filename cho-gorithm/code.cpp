#include <iostream>
#include <string>
#include <array>
using namespace std;

int arr[1001][1001];
array<array<string, 1001>, 1001> arr2;

string small(string& str1, string& str2){
    if(str1 >= str2){
        return str2;
    }
    else{
        return str1;
    }
}

int main(void){
    string str, result, temp;
    cin >> str;

    for(int i=0; i<str.length(); i++){
        arr[i][i] = 1;
        arr2[i][i] = str[i];
    }

    for(int i=1; i<str.length(); i++){
        for(int j=0; j<(str.length()-i); j++){
            if(str[j] == str[i+j]){
                arr[j][i+j] = arr[j+1][i+j-1] + 2;
                arr2[j][i+j] = str[j] + arr2[j+1][i+j-1] + str[j];
            }

            if(arr[j][i+j] < arr[j][i+j-1]){
                arr[j][i+j] = arr[j][i+j-1];
                arr2[j][i+j] = arr2[j][i+j-1];
            }
            else if(arr[j][i+j] == arr[j][i+j-1]){
                arr2[j][i+j] = small(arr2[j][i+j], arr2[j][i+j-1]);
            }

            if(arr[j][i+j] < arr[j+1][i+j]){
                arr[j][i+j] = arr[j+1][i+j];
                arr2[j][i+j] = arr2[j+1][i+j];
            }
            else if(arr[j][i+j] == arr[j+1][i+j]){
                arr2[j][i+j] = small(arr2[j][i+j], arr2[j+1][i+j]);
            }
        }
    }

    cout << arr2[0][str.length()-1] << endl;
    return 0;
}
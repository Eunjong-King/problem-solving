#include <iostream>
#include <string>
using namespace std;

string s, t;
bool isBack = false;

void recursive(int find_alphabet_index, int from_index){
    if(find_alphabet_index == t.length()){
        isBack = true;
        return;
    }

    int gap;
    for(int i=from_index; i<s.length(); i++){
        if(s[i] == t[find_alphabet_index]){
            gap = i - from_index;
            if(from_index != 0 && gap%2 != 0){
                continue;
            }
            else if(find_alphabet_index+1 == t.length() && (s.length()-i)%2 == 0){
                continue;
            }
            recursive(find_alphabet_index+1, i+1);
        }
    }
}

int main(void){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> s >> t;
        recursive(0, 0);
        if(isBack){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        isBack = false;
    }
}
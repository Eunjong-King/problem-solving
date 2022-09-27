#include <string>
#include <iostream>
using namespace std;

string inp;

bool muzisung(int& s_index, int& e_index){
    while(true){
        if(s_index >= e_index){
            return true;
        }
        else{
            if(inp[s_index] == inp[e_index]){
                ++s_index;
                --e_index;
                continue;
            }
            else{
                return false;
            }
        }
    }
}

int main(void){
    int N, str_size;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> inp;
        str_size = inp.length();

        int left_index=0, right_index=str_size-1;
        bool is_perfect_palin = muzisung(left_index, right_index);

        if(is_perfect_palin){
            cout << 1 << endl;
        }
        else{
            int temp_left_1 = left_index+1, temp_right_1 = right_index;
            int temp_left_2 = left_index, temp_right_2 = right_index-1;
            if(muzisung(temp_left_1, temp_right_1)){
                cout << 2 << endl;
            }
            else if(muzisung(temp_left_2, temp_right_2)){
                cout << 2 << endl;
            }
            else{
                cout << 3 << endl;
            }
        }
    }
    return 0;
}
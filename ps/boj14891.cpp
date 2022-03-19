#include <iostream>
using namespace std;

int K, one_right=2, two_left=6, two_right=2, three_left=6, three_right=2, four_left=6;
int arr[5][8];
int turn[100][2];
int gear_direction[5];

void input(){
    for(int i=1; i<=4; ++i){
        string inp;
        cin >> inp;
        for(int j=0; j<8; ++j){
            arr[i][j] = inp[j] - '0';
        }
    }

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> turn[i][0] >> turn[i][1];
    }

    return;
}

bool gear_turn(int from_gear, int to_gear, int& direct, bool turn_from_gear, bool turn_to_gear){
    int from_gear_index = (from_gear < to_gear) ? (gear_direction[from_gear]+2)%8 : (gear_direction[from_gear]+6)%8;
    int to_gear_index = (from_gear > to_gear) ? (gear_direction[to_gear]+2)%8 : (gear_direction[to_gear]+6)%8;

    if(turn_from_gear) {
        if (direct == 1) {
            gear_direction[from_gear] = (gear_direction[from_gear] + 7) % 8;
        } else {
            gear_direction[from_gear] = (gear_direction[from_gear] + 1) % 8;
        }
    }

    if(arr[from_gear][from_gear_index] == arr[to_gear][to_gear_index]){
        return false;
    }
    else{
        direct *= -1;
        if(turn_to_gear) {
            if (direct == 1) {
                gear_direction[to_gear] = (gear_direction[to_gear] + 7) % 8;
            } else {
                gear_direction[to_gear] = (gear_direction[to_gear] + 1) % 8;
            }
        }
        return true;
    }
}

void solve(){
    input();

    bool is_turn;
    int direct, direct2;
    for(int i=0; i<K; i++){
        direct = turn[i][1];
        direct2 = turn[i][1];

        if(turn[i][0] == 1){
            is_turn = gear_turn(1, 2, direct, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(2, 3, direct, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(3, 4, direct, true, true);
        }
        else if(turn[i][0] == 2){
            is_turn = gear_turn(2, 1, direct, false, true);
            is_turn = gear_turn(2, 3, direct2, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(3, 4, direct2, true, true);
        }
        else if(turn[i][0] == 3){
            is_turn = gear_turn(3, 4, direct, false, true);
            is_turn = gear_turn(3, 2, direct2, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(2, 1, direct2, true, true);
        }
        else{
            is_turn = gear_turn(4, 3, direct, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(3, 2, direct, true, false);
            if(is_turn == false){
                continue;
            }
            is_turn = gear_turn(2, 1, direct, true, true);
        }
    }

    int sum=0, two=1;
    for(int i=1; i<=4; i++){
        if(arr[i][gear_direction[i]] == 1){
            sum += two;
        }
        two *= 2;
    }

    cout << sum << endl;

    return;
}

int main(void){
    solve();

    return 0;
}
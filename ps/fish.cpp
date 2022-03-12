#include <iostream>
using namespace std;

int k, arr[10002];

void inp(){
    for(int i=1; i<=k; i++){
        cin >> arr[i];
    }

    return;
}

int find_diff(){
    for(int i=1; i<=k; i++){
        if(arr[i] != i){
            return i;
        }
    }
    return 0;
}

void find_from(int& from_index, int to_value){
    bool is_plus = arr[from_index] > 0;

    if(arr[from_index] == to_value){
        return;
    }

    for(int i=from_index+1; i<=k; i++){
        if((arr[i]>0) != is_plus){
            return;
        }
        if(arr[i] == to_value){
            return;
        }
        if(arr[i]-arr[i-1] != 1){
            from_index = i;
            return;
        }
    }

    return;
}

int find_to(int& from_index, int& to_value){
    int to_index;
    for(int i=from_index; i<=k; i++){
        if(abs(arr[i]) == abs(to_value)){
            if(arr[i]*to_value < 0){
                to_value *= -1;
            }
            to_index = i;
            if(to_index+1 <= k && arr[to_index+1] - arr[to_index] == 1) {
                ++to_value;
            }
            else{
                return to_index;
            }
        }
    }
    return 0;
}

void arr_swap(int from_index, int to_index){
    int gap = to_index-from_index;
    bool is_odd = (gap%2==0);
    int index = from_index + gap/2;
    if(is_odd){
        arr[index] *= -1;
    }

    while(from_index < to_index){
        int temp = arr[to_index];
        arr[to_index] = -arr[from_index];
        arr[from_index] = -temp;
        ++from_index;
        --to_index;
    }
    return;
}

void solve(){
    int from_index = find_diff();
    int to_value = -from_index;
    find_from(from_index, to_value);
    int to_index = find_to(from_index, to_value);
    if(to_index == 0){
        cout << "over" << '\n';
        return;
    }
    arr_swap(from_index, to_index);

    from_index = find_diff();
    if(from_index == 0){
        cout << "one" << '\n';
        return;
    }
    to_value = -from_index;
    find_from(from_index, to_value);
    to_index = find_to(from_index, to_value);
    if(to_index == 0){
        cout << "over" << '\n';
        return;
    }
    arr_swap(from_index, to_index);

    from_index = find_diff();
    if(from_index == 0){
        cout << "two" << '\n';
    }
    else{
        cout << "over" << '\n';
    }

    return;
}


int main(void){
    int T=5;

    cin >> k;
    while(T--){
        inp();
        solve();
    }
}
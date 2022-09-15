#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);

    for(int i=0; i<N; i++){
        cin >> nums[i];
    }

    int start = 0, end = N-1;
    int min_value = 2100000000;
    int idx1, idx2;

    while (start < end){
        int new_value = nums[start] + nums[end];

        if(abs(new_value) < min_value){
            min_value = abs(new_value);
            idx1 = start;
            idx2 = end;
        }

        if(new_value < 0){
            start++;
        }
        else{
            end--;
        }
    }

    cout << nums[idx1] << " " << nums[idx2] << endl;

    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<int> num(N);

    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
    }

    sort(num.begin(), num.end());

    int start = 0, end = N-1;
    int sum_min = 2100000000;
    int sum_temp, ans1=0, ans2=N-1;
    while(start < end){
        sum_temp = num[start] + num[end];

        if(abs(sum_temp) < sum_min){
            sum_min = abs(sum_temp);
            ans1 = start;
            ans2 = end;
        }

        if(sum_temp == 0){
            break;
        }

        if(sum_temp < 0){
            start++;
        }
        else{
            end--;
        }
    }

    printf("%d %d\n", num[ans1], num[ans2]);

    return 0;
}
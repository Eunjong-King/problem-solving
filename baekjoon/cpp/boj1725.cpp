#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

void init(vi& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = start;
        return;
    }

    int mid = (start + end)/2;
    init(tree, nums, node*2, start, mid);
    init(tree, nums, node*2+1, mid+1, end);

    tree[node] = nums[tree[node*2]] <= nums[tree[node*2+1]] ? tree[node*2] : tree[node*2+1];
}

int query(vi& tree, vi& nums, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return -1;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    int left_index = query(tree, nums, node*2, start, mid, left, right);
    int right_index = query(tree, nums, node*2+1, mid+1, end, left, right);

    if(left_index == -1){
        return right_index;
    } else if(right_index == -1){
        return left_index;
    } else{
        return nums[left_index] <= nums[right_index] ? left_index : right_index;
    }
}

int get_max(vi& tree, vi& nums, int left, int right){
    int min_index = query(tree, nums, 1, 1, nums.size()-1, left, right);

    int area = nums[min_index] * (right-left+1);
    if(left <= min_index-1) {
        area = max(get_max(tree, nums, left, min_index - 1), area);
    }
    if(min_index+1 <= right) {
        area = max(get_max(tree, nums, min_index + 1, right), area);
    }

    return area;
}

int main(){
    int N;
    scanf("%d", &N);

    vi nums(N+1);
    vi tree(4*(N+1));
    for(int i=1; i<=N; i++){
        scanf("%d", &nums[i]);
    }

    init(tree, nums, 1, 1, N);

    printf("%d", get_max(tree, nums,1, N));

    return 0;
}

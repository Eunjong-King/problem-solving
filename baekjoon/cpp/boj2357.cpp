#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int make_tree(vector<int>& tree, vector<int>& nums, int node, int start, int end, bool is_min){
    if(start == end){
        tree[node] = nums[start];
        return tree[node];
    }

    int mid = (start + end)/2;
    int left = make_tree(tree, nums, node*2, start, mid, is_min);
    int right = make_tree(tree, nums, node*2+1, mid+1, end, is_min);

    if(is_min)
        tree[node] = min(left, right);
    else
        tree[node] = max(left, right);

    return tree[node];
}

int find(vector<int>& tree, int node, int start, int end, int left, int right, bool is_min){
    if(left > end || right < start){
        if(is_min)
            return 2147483646;
        else
            return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    int left_value = find(tree, node*2, start, mid, left, right, is_min);
    int right_value = find(tree, node*2+1, mid+1, end, left, right, is_min);

    if(is_min)
        return min(left_value, right_value);
    else
        return max(left_value, right_value);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int depth = (int)ceil(log2(N));
    int size = 1 << (depth+1);

    vector<int> nums(N);
    vector<int> stree(size);
    vector<int> btree(size);

    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    make_tree(stree, nums, 1, 0, N-1, true);
    make_tree(btree, nums, 1, 0, N-1, false);

    int a, b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        printf("%d %d\n", find(stree, 1, 1, N, a, b, true), find(btree, 1, 1, N, a, b, false));
    }

    return 0;
}
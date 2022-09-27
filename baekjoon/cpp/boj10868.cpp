#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

int make_tree(vi& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return tree[node];
    }

    int mid = (start + end)/2;
    int left_min = make_tree(tree, nums, node*2, start, mid);
    int right_min = make_tree(tree, nums, node*2+1, mid+1, end);

    tree[node] = min(left_min, right_min);
    return tree[node];
}

int find_min(vi& tree, int node, int start, int end, int left, int right){
    if(right < start || end < left) {
        return 2100000000;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    int left_min = find_min(tree, node*2, start, mid, left, right);
    int right_min = find_min(tree, node*2+1, mid+1, end, left, right);

    return min(left_min, right_min);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    vi nums(N);
    vi tree(4*N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    make_tree(tree, nums, 1, 0, N-1);

    int a, b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", find_min(tree, 1, 1, N, a, b));
    }

    return 0;
}
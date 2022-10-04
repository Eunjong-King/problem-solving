#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

void init(vi& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = start;
        return;
    }

    init(tree, nums, node*2, start, (start+end)/2);
    init(tree, nums, node*2+1, (start+end)/2+1, end);

    if(nums[tree[node*2]] > nums[tree[node*2+1]]){
        tree[node] = tree[node*2+1];
    } else if(nums[tree[node*2]] < nums[tree[node*2+1]]){
        tree[node] = tree[node*2];
    } else {
        tree[node] = tree[node*2] > tree[node*2+1] ? tree[node*2+1] : tree[node*2];
    }
}

void modify(vi& tree, vi& nums, int node, int start, int end, int index, int value){
    if(index < start || end < index){
        return;
    }

    if(start == end){
        tree[node] = index;
        return;
    }

    modify(tree, nums, node*2, start, (start+end)/2, index, value);
    modify(tree, nums, node*2+1, (start+end)/2+1, end, index, value);

    if(nums[tree[node*2]] > nums[tree[node*2+1]]){
        tree[node] = tree[node*2+1];
    } else if(nums[tree[node*2]] < nums[tree[node*2+1]]){
        tree[node] = tree[node*2];
    } else {
        tree[node] = tree[node*2] > tree[node*2+1] ? tree[node*2+1] : tree[node*2];
    }
}

int query(vi& tree, vi& nums, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    int left_value = query(tree, nums, node*2, start, (start+end)/2, left, right);
    int right_value = query(tree, nums, node*2+1, (start+end)/2+1, end, left, right);

    return nums[left_value] > nums[right_value] ? left_value : right_value;
}

int main(){
    int N;
    scanf("%d", &N);
    vi nums(N+1);

    for(int i=1; i<=N; i++){
        scanf("%d", &nums[i]);
    }
    nums[0] = 2000000000;

    vi tree(4*(N+1));
    init(tree, nums, 1, 1, N);

    int M;
    scanf("%d", &M);

    int a, b, c;
    while(M--){
        scanf("%d", &a);

        if(a==1) {
            scanf("%d %d", &b, &c);
            nums[b] = c;
            modify(tree, nums, 1, 1, N, b, c);
        } else {
            printf("%d\n", tree[1]);
        }
    }

    return 0;
}
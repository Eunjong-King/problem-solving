#include <iostream>
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

    tree[node] = nums[tree[node*2]] > nums[tree[node*2+1]] ? tree[node*2+1] : tree[node*2];
}

void modify(vi& tree, vi& nums, int node, int start, int end, int index){
    if(index < start || end < index){
        return;
    }

    if(start == end){
        tree[node] = index;
        return;
    }

    modify(tree, nums, node*2, start, (start+end)/2, index);
    modify(tree, nums, node*2+1, (start+end)/2+1, end, index);
    tree[node] = nums[tree[node*2]] > nums[tree[node*2+1]] ? tree[node*2+1] : tree[node*2];
}

int query(vi& tree, vi& nums, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int left_index = query(tree, nums, node*2, start, (start+end)/2, left, right);
    int right_index = query(tree, nums, node*2+1, (start+end)/2+1, end, left, right);

    return nums[left_index] > nums[right_index] ? right_index : left_index;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vi nums(N+1);
    for(int i=1; i<=N; i++){
        cin >> nums[i];
    }
    nums[0] = 2000000000;

    vi tree(4*(N+1));
    init(tree, nums, 1, 1, N);

    int M;
    cin >> M;

    int a, b, c;
    while(M--){
        cin >> a >> b >> c;
        if(a==1){
            nums[b] = c;
            modify(tree, nums, 1, 1, N, b);
        } else{
            printf("%d\n", query(tree, nums, 1, 1, N, b, c));
        }
    }
}

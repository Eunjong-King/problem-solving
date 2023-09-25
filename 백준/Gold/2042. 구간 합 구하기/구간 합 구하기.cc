#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll make_segment_tree(vector<ll>& tree, vector<ll>& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    ll left = make_segment_tree(tree, nums, node*2, start, mid);
    ll right = make_segment_tree(tree, nums, node*2+1, mid+1, end);
    tree[node] = left + right;

    return tree[node];
}

// left-right 값 구하고 싶음
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end) / 2;
    ll left_sum = sum(tree, node*2, start, mid, left, right);
    ll right_sum = sum(tree, node*2+1, mid+1, end, left, right);

    return left_sum + right_sum;
}

void update(vector<ll>& tree, int node, ll diff, int index, int start, int end){
    if(start > index || end < index){
        return;
    }

    tree[node] += diff;

    if(start == end){
        return;
    }

    int mid = (start + end) / 2;
    update(tree, node*2, diff, index, start, mid);
    update(tree, node*2+1, diff, index, mid+1, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int treeDepth = ceil(log2(N));
    int treeSize = 1 << (treeDepth + 1);

    vector<ll> nums(N);
    vector<ll> tree(treeSize);

    for(int i=0; i<N; i++){
        cin >> nums[i];
    }

    make_segment_tree(tree, nums, 1, 0, N-1);

    int a, b;
    ll c;
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;

        if(a == 1){
            ll diff = c - nums[b-1];
            update(tree, 1, diff, b, 1, N);
            nums[b-1] = c;
        } else if (a == 2){
            cout << sum(tree, 1, 1, N, b, c) << endl;
        }
    }

    return 0;
}

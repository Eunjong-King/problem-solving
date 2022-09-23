#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

ll make_tree(vll& tree, vll& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return tree[node];
    }

    int mid = (start + end)/2;
    ll left = make_tree(tree, nums, node*2, start, mid);
    ll right = make_tree(tree, nums, node*2+1, mid+1, end);

    tree[node] = left + right;

    return tree[node];
}

ll sum(vll& tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    ll left_sum = sum(tree, node*2, start, mid, left, right);
    ll right_sum = sum(tree, node*2+1, mid+1, end, left, right);

    return left_sum+right_sum;
}

void update(vll& tree, int node, int index, int start, int end, ll diff){
    if(index < start || end < index){
        return;
    }

    tree[node] += diff;

    if(start == end){
        return;
    }

    int mid = (start + end)/2;
    update(tree, node*2, index, start, mid, diff);
    update(tree, node*2+1, index, mid+1, end, diff);
}

int main(){
    int N, Q;
    cin >> N >> Q;

    vll nums(N);
    for(int i=0; i<N; i++){
        scanf("%lld", &nums[i]);
    }

    int depth = (int)ceil(log2(N));
    int size = 1 << (depth+1);

    vll tree(size);

    make_tree(tree, nums, 1, 0, N-1);

    int x, y, a;
    ll b;
    for(int i=0; i<Q; i++){
        scanf("%d %d %d %lld", &x, &y, &a, &b);

        if(x>y){
            int temp = x;
            x = y;
            y = temp;
        }

        printf("%lld\n", sum(tree, 1, 1, N, x, y));

        ll diff = b - nums[a-1];
        update(tree, 1, a, 1, N, diff);
        nums[a-1] = b;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void update(vi& tree, int node, int start, int end, int value, int diff){
    if(start == end){
        tree[node] += diff;
        return;
    }

    int mid = (start+end)/2;
    if(value <= mid) {
        update(tree, node * 2, start, mid, value, diff);
    }
    else {
        update(tree, node * 2 + 1, mid + 1, end, value, diff);
    }

    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(vi& tree, int node, int start, int end, int k){
    if(start == end){
        return start;
    }

    int mid = (start+end)/2;
    if(k <= tree[node*2]){
        return query(tree, node*2, start, mid, k);
    } else{
        return query(tree, node*2+1, mid+1, end, k-tree[node*2]);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vi nums(N);
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }

    vi tree(4*65538, 0);
    for(int i=0; i<(K-1); i++){
        update(tree, 1, 0, 65535, nums[i], 1);
    }

    long long result = 0;
    int index = 0;
    for(int i=(K-1); i<N; i++){
        update(tree, 1, 0, 65535, nums[i], 1);
        result += (long long)(query(tree, 1, 0, 65535, (K+1)/2));
        update(tree, 1, 0, 65535, nums[index], -1);
        index++;
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void init(vll& tree, vll& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return;
    }

    init(tree, nums, node*2, start, (start+end)/2);
    init(tree, nums, node*2+1, (start+end)/2+1, end);

    tree[node] = tree[node*2] + tree[node*2+1];
}

void update_lazy(vll& tree, vll& lazy, int node, int start, int end){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right, ll diff){
    update_lazy(tree, lazy, node, start, end);

    if(end < left || right < start){
        return;
    }
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * diff;
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }

    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);

    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vll& tree, vll& lazy, int node, int start, int end, int left, int right){
    update_lazy(tree, lazy, node, start, end);
    if(end < left || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    ll left_value = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    ll right_value = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);

    return left_value+right_value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    vll nums(N+1);
    vll tree(4*(N+1));
    vll lazy(4*(N+1));

    for(int i=1; i<=N; i++){
        cin >> nums[i];
    }

    init(tree, nums, 1, 1, N);

    int a, b, c;
    ll d;
    for(int i=0; i<M+K; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update_range(tree, lazy, 1, 1, N, b, c, d);
        } else {
            cin >> b >> c;
            cout << query(tree, lazy, 1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}
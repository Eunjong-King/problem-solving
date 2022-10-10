#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;


void init(vll& tree, vi& nums, int node, int start, int end){
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

void update_range(vll& tree, vll& lazy, int node, int start, int end, int left, int right, int diff){
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

ll query(vll& tree, vll& lazy, int node, int start, int end, int index){
    update_lazy(tree, lazy, node, start, end);

    if(start == end){
        return tree[node];
    }

    int mid = (start+end)/2;
    ll answer;
    if (index <= mid){
        answer = query(tree, lazy, node*2, start, mid, index);
    } else {
        answer = query(tree, lazy, node*2+1, mid+1, end, index);
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N;
    vi nums(N+1);
    for(int i=1; i<=N; i++){
        cin >> nums[i];
    }

    vll tree(4*(N+1), 0);
    vll lazy(4*(N+1), 0);

    init(tree, nums, 1, 1, N);

    int a, b, c, d;
    cin >> M;
    while(M--){
        cin >> a >> b;

        if(a == 1){
            cin >> c >> d;
            update_range(tree, lazy, 1, 1, N, b, c, d);
        } else {
            cout << query(tree, lazy, 1, 1, N, b) << '\n';
        }
    }

    return 0;
}
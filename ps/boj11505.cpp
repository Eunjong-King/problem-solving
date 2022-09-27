#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

ll init(vll& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = (ll)nums[start];
        return tree[node];
    }

    int mid = (start + end)/2;
    ll left = init(tree, nums, node*2, start, mid);
    ll right = init(tree, nums, node*2+1, mid+1, end);

    tree[node] = (left * right) % 1000000007;
    return tree[node];
}

void update(vll& tree, int node, int start, int end, int& index, int& now){
    if(index < start || end < index){
        return;
    }

    if(start == end){
        tree[node] = now;
        return;
    }

    int mid = (start+end)/2;
    update(tree, node*2, start, mid, index, now);
    update(tree, node*2+1, mid+1, end, index, now);

    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
}

ll query(vll& tree, int node, int start, int end, int& left, int& right){
    if(right < start || end < left){
        return 1;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    ll left_mul = query(tree, node*2, start, mid, left, right);
    ll right_mul = query(tree, node*2+1, mid+1, end, left, right);

    return (left_mul * right_mul) % 1000000007;
}

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vi nums(N+1, 1);
    vll tree(4*(N+1), 1);
    for(int i=1; i<=N; i++){
        scanf("%d", &nums[i]);
    }

    init(tree, nums, 1, 1, N);

    int a, b, c;
    for(int i=0; i<M+K; i++){
        scanf("%d %d %d", &a, &b, &c);

        if(a==1){
            update(tree, 1, 1, N, b, c);
        }
        else{
            printf("%lld\n", query(tree, 1, 1, N, b, c));
        }
    }

    return 0;
}

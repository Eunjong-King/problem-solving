#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void init(vll& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return;
    }

    init(tree, nums, node*2, start, (start+end)/2);
    init(tree, nums, node*2+1, (start+end)/2+1, end);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void modify(vll& tree, int node, int start, int end, int index, int value){
    if(index < start || end < index){
        return;
    }

    if(start == end){
        tree[node] = value;
        return;
    }

    modify(tree, node*2, start, (start+end)/2, index, value);
    modify(tree, node*2+1, (start+end)/2+1, end, index, value);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

ll query(vll& tree, int node, int start, int end, int left, int right){
    if(right < start || end < left){
        return 20000000000000;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    ll left_min = query(tree, node*2, start, (start+end)/2, left, right);
    ll right_min = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return min(left_min, right_min);
}

int main(){
    int N, M;
    scanf("%d", &N);

    vi nums(N+1);
    vll tree(4*(N+1));

    for(int i=1; i<=N; i++){
        scanf("%d", &nums[i]);
    }

    init(tree, nums, 1, 1, N);

    scanf("%d", &M);

    int a, b, c;
    while(M--){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1){
            modify(tree, 1, 1, N, b, c);
            nums[b] = c;
        } else{
            printf("%d\n", query(tree, 1, 1, N, b, c));
        }
    }

    return 0;
}

/*
 *
 *          2
 *     3         2
 *  4    3     2  3
 * 5 4
 */
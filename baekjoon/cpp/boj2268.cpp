#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void modify(vll& tree, int node, int index, int start, int end, ll diff){
    if(index < start || end < index){
        return;
    }

    tree[node] += diff;

    if(start == end){
        return;
    }

    int mid = (start + end)/2;
    modify(tree, node*2, index, start, mid, diff);
    modify(tree, node*2+1, index, mid+1, end, diff);
}

ll query(vll& tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start+end)/2;
    ll left_sum = query(tree, node*2, start, mid, left, right);
    ll right_sum = query(tree, node*2+1, mid+1, end, left, right);

    return left_sum + right_sum;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> nums(N+1, 0);
    vll tree(4*(N+1), 0);

    int a, b, c;
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            if(b > c){
                swap(b, c);
            }
            printf("%lld\n", query(tree, 1, 1, N, b, c));
        }
        else{
            ll diff = (ll)(c - nums[b]);
            modify(tree, 1, b, 1, N, diff);
            nums[b] = c;
        }
    }

    return 0;
}
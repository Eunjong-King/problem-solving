#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void modify(vll& tree, int node, int start, int end, int index, int diff){
    if(index < start || end < index){
        return;
    }

    tree[node] += diff;

    if(start == end){
        return;
    }

    modify(tree, node*2, start, (start+end)/2, index, diff);
    modify(tree, node*2+1, (start+end)/2+1, end, index, diff);
}

ll query(vll& tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    ll left_value = query(tree, node*2, start, (start+end)/2, left, right);
    ll right_value = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return left_value+right_value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vll nums(N+1, 0);
    vll tree(4*(N+1));

    int a, b, c;
    while(Q--){
        cin >> a >> b >> c;

        if(a==1){
            modify(tree, 1, 1, N, b, c);
            nums[b] += c;
        } else{
            cout << query(tree, 1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}
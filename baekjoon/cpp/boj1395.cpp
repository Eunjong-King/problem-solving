#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void update_lazy(vi& tree, vi& lazy, int node, int start, int end){
    if(lazy[node]%2 == 1){
        tree[node] = (end - start + 1) - tree[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vi& tree, vi& lazy, int node, int start, int end, int left, int right){
    update_lazy(tree, lazy, node, start, end);

    if(end < left || right < start){
        return;
    }

    if(left <= start && end <= right){
        tree[node] = (end - start + 1) - tree[node];
        if(start != end){
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return;
    }

    update_range(tree, lazy, node*2, start, (start+end)/2, left, right);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(vi& tree, vi& lazy, int node, int start, int end, int left, int right){
    update_lazy(tree, lazy, node, start, end);

    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    int left_value = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    int right_value = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);

    return left_value + right_value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vi tree(4*(N+1), 0);
    vi lazy(4*(N+1), 0);

    int a, b, c;
    while(M--){
        cin >> a >> b >> c;

        if(a == 0){
            update_range(tree, lazy, 1, 1, N, b, c);
        } else {
            cout << query(tree, lazy, 1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}
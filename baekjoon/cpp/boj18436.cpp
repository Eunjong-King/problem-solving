#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void init(vi& even_tree, vi& nums, int node, int start, int end){
    if(start == end){
        even_tree[node] = nums[start] % 2 == 0 ? 1 : 0;
        return;
    }

    init(even_tree, nums, node*2, start, (start+end)/2);
    init(even_tree, nums, node*2+1, (start+end)/2+1, end);

    even_tree[node] = even_tree[node*2] + even_tree[node*2+1];
}

void modify(vi& even_tree, int node, int start, int end, int index, int diff){
    if(index < start || end < index){
        return;
    }

    even_tree[node] += diff;

    if(start == end){
        return;
    }

    modify(even_tree, node*2, start, (start+end)/2, index, diff);
    modify(even_tree, node*2+1, (start+end)/2+1, end, index, diff);
}

int query(vi& even_tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return even_tree[node];
    }

    int left_value = query(even_tree, node*2, start, (start+end)/2, left, right);
    int right_value = query(even_tree, node*2+1, (start+end)/2+1, end, left, right);

    return left_value + right_value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vi nums(N+1);
    for(int i=1; i<=N; i++){
        cin >> nums[i];
    }

    vi even_tree(4*(N+1));
    init(even_tree, nums, 1, 1, N);

    int M;
    cin >> M;

    int a, b, c;
    while(M--){
        cin >> a >> b >> c;

        if(a == 1){
            if(nums[b]%2 == c%2){
                continue;
            }
            if(c%2 == 0){
                modify(even_tree, 1, 1, N, b, 1);
                nums[b] = c;
            } else {
                modify(even_tree, 1, 1, N, b, -1);
                nums[b] = c;
            }
        } else if(a == 2){
            int even_count = query(even_tree, 1, 1, N, b, c);
            cout << even_count << '\n';
        } else {
            int even_count = query(even_tree, 1, 1, N, b, c);
            cout << c - b + 1 - even_count << '\n';
        }
    }
}
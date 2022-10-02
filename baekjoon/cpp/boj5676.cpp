#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void init(vi& tree, vi& nums, int node, int start, int end){
    if(start == end){
        tree[node] = nums[start];
        return;
    }

    init(tree, nums, node*2, start, (start+end)/2);
    init(tree, nums, node*2+1, (start+end)/2+1, end);

    tree[node] = tree[node*2] * tree[node*2+1];
}

void modify(vi& tree, int node, int start, int end, int index, int value){
    if(index < start || end < index){
        return;
    }

    if(start == end){
        tree[node] = value;
        return;
    }

    modify(tree, node*2, start, (start+end)/2, index, value);
    modify(tree, node*2+1, (start+end)/2+1, end, index, value);
    tree[node] = tree[node*2] * tree[node*2+1];
}

int query(vi& tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 1;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int left_value = query(tree, node*2, start, (start+end)/2, left, right);
    int right_value = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return left_value * right_value;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    while(cin >> N >> M) {
        vi nums(N + 1);
        int num;
        for (int i = 1; i <= N; i++) {
            cin >> num;

            if (num < 0) {
                nums[i] = -1;
            } else if (num > 0) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }

        vi tree(4 * (N + 1));
        init(tree, nums, 1, 1, N);

        char a;
        int b, c;
        while (M--) {
            cin >> a >> b >> c;

            if (a == 'C') {
                int value;

                if (c < 0) {
                    value = -1;
                } else if (c > 0) {
                    value = 1;
                } else {
                    value = 0;
                }

                modify(tree, 1, 1, N, b, value);
            } else {
                int result = query(tree, 1, 1, N, b, c);
                char r;

                if (result < 0) {
                    r = '-';
                } else if (result > 0) {
                    r = '+';
                } else {
                    r = '0';
                }

                cout << r;
            }
        }
        cout << '\n';
    }
    return 0;
}

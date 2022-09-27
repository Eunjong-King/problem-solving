#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int make_tree(vi& tree, vi& heights, int node, int start, int end){
    if(start == end){
        tree[node] = start;
        return start;
    }

    int mid = (start + end)/2;
    int left_index = make_tree(tree, heights, node*2, start, mid);
    int right_index = make_tree(tree, heights, node*2+1, mid+1, end);

    if(heights[left_index] <= heights[right_index]){
        tree[node] = left_index;
    }
    else{
        tree[node] = right_index;
    }

    return tree[node];
}

// 전체 start~end 구간에서 left~right 범위 중 height 최소를 가지는 index
int query(vi& tree, vi& heights, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return -1;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;
    int left_min_index = query(tree, heights, node*2, start, mid, left, right);
    int right_min_index = query(tree, heights, node*2+1, mid+1, end, left, right);

    if(left_min_index == -1){
        return right_min_index;
    } else if (right_min_index == -1){
        return left_min_index;
    }

    if(heights[left_min_index] <= heights[right_min_index]){
        return left_min_index;
    }
    else{
        return right_min_index;
    }
}

ll max_area(vi& tree, vi& heights, int left, int right){
    int min_index = query(tree, heights, 1, 1, heights.size()-1, left, right);

    ll area = (ll)heights[min_index] * (ll)(right - left + 1);

    if(left <= min_index-1) {
        ll left_area = max_area(tree, heights, left, min_index - 1);
        area = max(area, left_area);
    }

    if(min_index+1 <= right) {
        ll right_area = max_area(tree, heights, min_index + 1, right);
        area = max(area, right_area);
    }

    return area;
}

int main(){
    int n;
    vi heights;
    vi tree;

    while(true) {
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        heights = vi(n+1);
        tree = vi(4*(n+1));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &heights[i]);
        }

        make_tree(tree, heights, 1, 1, n);

        printf("%lld\n", max_area(tree, heights, 1, n));
    }

    return 0;
}
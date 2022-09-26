#include <cstdio>
#include <vector>
using namespace std;

void update(vector<int>& tree, int index, int start, int end, int flavor, int count){
    if(start == end){
        tree[index] += count;
        return;
    }

    int mid = (start + end)/2;
    if(flavor <= mid){
        update(tree, index*2, start, mid, flavor, count);
    }
    else {
        update(tree, index*2+1, mid+1, end, flavor, count);
    }

    tree[index] += count;
}

int pick(vector<int>& tree, int index, int start, int end, int p){
    if(start == end){
        tree[index]--;
        return start;
    }

    int mid = (start + end)/2;
    int idx;
    if(p <= tree[index*2]){
        idx = pick(tree, index*2, start, mid, p);
    } else {
        idx = pick(tree, index*2+1, mid+1, end, p - tree[index*2]);
    }

    tree[index]--;

    return idx;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> tree(4*1000001, 0);

    int a, b, c;
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);

        if(a == 1){
            printf("%d\n", pick(tree, 1, 1, 1000000, b));
        }
        else {
            scanf("%d", &c);
            update(tree, 1, 1, 1000000, b, c);
        }
    }
}
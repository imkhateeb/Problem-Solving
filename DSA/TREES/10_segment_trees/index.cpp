#include <bits/stdc++.h>
using namespace std;


int findMaxBetweenRange(int n, int i, int j){

    

}

int fillTheSegmentTree(vector<int> &seg_tree, int low, int high, int idx, vector<int>& v){

    if(high == low){
        return seq_tree[idx] = v[high];
    }

    int mid = (high+low)/2;

    int leftMax = fillTheSegmentTree(seg_tree, low, mid, idx*2 + 1, v);
    int rightMax = fillTheSegmentTree(seg_tree, mid+1, high, idx*2 + 2, v);

    return seg_tree[idx] = max(leftMax, rightMax);
}


int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int>seg_tree(4*n, 0);
    fillTheSegmentTree(seg_tree, 0, n-1, 0, v);

    int q;
    cin >> q;

    while(q--){
        int i, j;
        cin >> i >> j;

        int maxElement = findMaxBetweenRange(n, i, j);

        cout << maxElement << endl;
    }

    return 0;
}
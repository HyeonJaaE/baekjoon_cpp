#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll init(vector<ll> &tree, vector<ll> &arr, int left, int right, int node){
    if(left == right){
        return tree[node] = arr[left];
    }
    else{
        return tree[node] = 
            init(tree, arr, left, (left+right) / 2, node * 2) +
            init(tree, arr, (left + right) / 2 + 1, right, node * 2 + 1);
    }
}

ll sum(vector<ll> &tree, int left, int right, int nodeleft, int noderight, int node){
    if(left > noderight || right < nodeleft) return 0;
    if(left <= nodeleft && noderight <= right) return tree[node];
    return sum(tree, left, right, nodeleft, (nodeleft + noderight) / 2, node * 2) + sum(tree, left, right, (nodeleft + noderight) / 2 + 1, noderight, node * 2 + 1);
}

void update(vector<ll> &tree, int target, ll diff, int nodeleft, int noderight, int node){
    if(nodeleft > target || noderight < target){
        return;
    }
    tree[node] += diff;
    if(nodeleft != noderight){
        update(tree, target, diff, nodeleft, (nodeleft + noderight) / 2, node * 2);
        update(tree, target, diff, (nodeleft + noderight) / 2 + 1, noderight, node * 2 + 1);
    }
}

int N, M, K;
vector<ll> tree, arr;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(N * 4);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    init(tree, arr, 0, N - 1, 1);
    for(int i = 0 ; i < M + K ; i++){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            //update
            update(tree, b - 1, c - arr[b-1], 0, N - 1, 1);
            arr[b - 1] = c;
        } else if (a == 2){
            //print sum
            cout << sum(tree, b - 1, c - 1, 0, N - 1, 1) << "\n";
        }
    }
    return 0;
}
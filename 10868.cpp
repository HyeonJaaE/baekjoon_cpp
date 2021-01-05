#include<bits/stdc++.h>
using namespace std;

const int MAXN = 400000;
const int INF = 1234567890;

vector<int> v;
int tree[MAXN];
int N, M;

int set_tree(int l, int r, int node){
    int m = (l + r) / 2;
    if(l == r) return tree[node] = v[l];
    return tree[node] = min(set_tree(l, m, node * 2), set_tree(m + 1, r, node * 2 + 1));
}

int get_tree(int l, int r, int node, int a, int b){
    int m = (l + r) / 2;
    if(r < a || l > b) return INF;
    if(a <= l && r <= b) return tree[node];
    return min(get_tree(l, m, node * 2, a, b), get_tree(m + 1, r, node * 2 + 1, a, b));
}

void solve(){
    for(int i = 0 ; i < M ; i++){
        int a, b;
        cin >> a >> b;
        cout << get_tree(0, N - 1, 1, a-1, b-1) << "\n";
    }
}

void init(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0 ; i < N ; i++){
        cin >> v[i];
    }
    set_tree(0, N - 1, 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;    
}
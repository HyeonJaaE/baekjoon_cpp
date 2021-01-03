#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int parent[MAXN];
int n, m;


int getParent(int node){
    if(parent[node] == node){
        return node;
    } else {
        return getParent(parent[node]);
    }
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }
}

void solve(){
    while(m--){
        int op, a, b; 
        cin >> op >> a >> b;
        if(a != b){
            a = getParent(a);
            b = getParent(b);
        }
        if(op == 0 && a != b){
            //union
            int smallerParent = min(a, b);
            parent[a] = smallerParent;
            parent[b] = smallerParent;
        } 
        if(op == 1){
            //check
            if(a == b){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}
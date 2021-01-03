#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int parent[10001];
priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> edges;
int V, E;
int ans = 0;

int getParent(int node){
    if(node == parent[node]) return parent[node];
    else return getParent(parent[node]);
}

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for(int i = 0 ; i <= V ; i++){
        parent[i] = i;
    }
    for(int i = 0 ; i < E ; i++){
        int A, B, C; cin >> A >> B >> C;
        edges.push(make_pair(C, pi(A, B)));
    }
}

void solve(){
    while(!edges.empty()){
        int weight = edges.top().first;
        int A = getParent(edges.top().second.first);
        int B = getParent(edges.top().second.second);
        edges.pop();
        if(A != B){
            parent[A] = min(A, B);
            parent[B] = min(A, B);
            ans += weight;
        }
    }
    cout << ans << "\n";
}

int main(){
    init();
    solve();
}
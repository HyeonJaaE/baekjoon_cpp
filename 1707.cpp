#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int visited[20001];
vector<int> adj[20001];
int K, V, E;

void DFS(int node){
    if(visited[node] == 0) visited[node] = 1;
    for(int i = 0 ; i < adj[node].size() ; i++){
        int nnode = adj[node][i];
        if(visited[nnode] == 0){
            if(visited[node] == 1) visited[nnode] = 2;
            else visited[nnode] = 1;
            DFS(nnode);
        }
    }
}

bool isBigraph(){
    for(int i = 1 ; i <= V ; i++){
        for(auto a: adj[i]){
            if(visited[a] == visited[i]) return false;
        }
    }
    return true;
}

void init(){
    cin >> V >> E;
    memset(visited, 0, sizeof(visited));
    for(int i = 1 ; i <= V ; i++){
        adj[i].clear();
    }
    for(int i = 0 ; i < E ; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void solve(){
    for(int i = 1 ; i <= V ; i++){
        if(visited[i] == 0) DFS(i);
    }
    if(isBigraph()) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    while(K--){
        init();
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
int indeg[32001];
int N, M;

bool check(){
    queue<int> q;
    for(int i = 1 ; i <= N ; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    if(q.empty()) return false;

    while(!q.empty()){
        int idx = q.front(); q.pop();
        indeg[idx] = -1;
        cout << idx << " ";
        for(auto del: adj[idx]){
            indeg[del] -= 1;
        }
    }
    return true;
}

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int from, to; cin >> from >> to;
        adj[from].push_back(to);
        indeg[to] += 1;
    }
}

void solve(){
    while(check());
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
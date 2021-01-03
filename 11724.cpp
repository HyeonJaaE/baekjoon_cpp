#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1001;
int visit[MAXN] = {0, };
vector<vector<int>> graph(MAXN);

void DFS(int root){
    for(auto _root: graph[root]){
        if(visit[_root] == 0){
            visit[_root] = 1;
            DFS(_root);
        }    
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   

    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){
            cnt += 1;
            visit[i] = 1;
            DFS(i);
        }     
    }

    cout << cnt;
}
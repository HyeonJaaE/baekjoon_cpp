#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
const int MAXN = 100001;

int visited[MAXN];
int dist[MAXN];
int N, K;

void BFS(){
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(idx + 1 < MAXN){
            dist[idx + 1] = min(dist[idx] + 1, dist[idx + 1]);
            if(visited[idx + 1] == -1){
                visited[idx + 1] = 1;
                q.push(idx + 1);
            }
        }
        if(idx - 1 >= 0){
            dist[idx - 1] = min(dist[idx] + 1, dist[idx - 1]);
            if(visited[idx - 1] == -1){
                visited[idx - 1] = 1;
                q.push(idx - 1);
            }
        }
        if(idx * 2 < MAXN){
            dist[idx * 2] = min(dist[idx], dist[idx * 2]);
            if(visited[idx * 2] == -1){
                visited[idx * 2] = 1;
                q.push(idx * 2);
            }
        }
    }
}

void init(){
    memset(visited, -1, sizeof(visited));
    for(int i = 0 ; i < MAXN ; i++)
        dist[i] = INF;
    cin >> N >> K;
    visited[N] = 0;
    dist[N] = 0;
}

void solve(){
    BFS();
    cout << dist[K] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
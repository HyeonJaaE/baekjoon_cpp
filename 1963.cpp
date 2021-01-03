#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 10000;
const int INF = 987654321;

vector<int> prime;
vector<int> adj[MAXN];
int dist[MAXN];
int check[MAXN];
int s, e;
int T;

void BFS(){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nnode: adj[node]){
            if(dist[nnode] == INF) q.push(nnode);
            dist[nnode] = min(dist[nnode], dist[node] + 1);
        }
    }
}
void init(){
    for(int i = 2 ; i < MAXN ; i++){
        if(!check[i]) check[i] = 1;
        for(int j = 2 ; j * i < MAXN ; j++)
            check[i * j] = -1;
    }
    
    for(int i = 1000 ; i < MAXN ; i++)
        if(check[i] == 1) prime.push_back(i);
    
    for(int i = 0 ; i < prime.size() ; i++){
        for(int j = 0 ; j < prime.size() ; j++){
            int a = prime[i], b = prime[j];
            int diff = 0;
            while(a != 0){
                if(a % 10 != b % 10) diff += 1;
                a /= 10;
                b /= 10;
            }
            if(diff == 1) adj[prime[i]].push_back(prime[j]);
        }
    }
}

void solve(){
    for(int i = 0 ; i < MAXN ; i++)
        dist[i] = INF;
    cin >> s >> e;
    dist[s] = 0;
    BFS();
    if(dist[e] == INF){
        cout << "Impossible\n";   
    } else {
        cout << dist[e] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> T;
    while(T--){
        solve();
    }    
}
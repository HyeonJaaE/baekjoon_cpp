#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXNM = 1001;

int toXdist[1001];
int fromXdist[1001];
vector<pi> adj[MAXNM];
vector<pi> adj_rev[MAXNM];
int N, M, X;

int ans = -1;

void dijkstra(vector<pi> (&graph)[MAXNM], int dist[MAXNM]){
    dist[X] = 0;
    priority_queue<pi> pq;
    for(auto g: graph[X])
        pq.push(g);

    while(!pq.empty()){
        //cout << pq.top().first << pq.top().second << "\n";
        int weight = -pq.top().first, node = pq.top().second;
        pq.pop();
        if(dist[node] != -1) continue;
        dist[node] = weight;
        for(auto g: graph[node]){
            //cout << "g : " << g.first << " , " << g.second << "\n";
            if(dist[g.second] == -1)
                pq.push(pi(g.first - weight, g.second));
        }
    }
}

void init(){
    cin >> N >> M >> X;
    for(int i = 0 ; i < M ; i++){
        int s, e, t; 
        cin >> s >> e >> t;
        adj[s].push_back(pi(-t, e));
        adj_rev[e].push_back(pi(-t, s));
    }
    memset(toXdist, -1, sizeof(toXdist));
    memset(fromXdist, -1, sizeof(fromXdist));
}

void solve(){
    dijkstra(adj, fromXdist);
    dijkstra(adj_rev, toXdist);
    for(int i = 1 ; i <= N ; i++)
        ans = max(ans, fromXdist[i] + toXdist[i]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int MAXN = 801;
const int INF = 987654321;

int visited[MAXN];
int dist[MAXN][3];
vector<pi> adj[MAXN];
int N, E;
int v1, v2;
int ans = INF;

void dijk(int start, int idx){
    priority_queue<pi> pq;
    pq.push(pi(0, start));
    while(!pq.empty()){
        int weight = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = 1;
        dist[node][idx] = min(dist[node][idx], weight);
        for(int i = 0 ; i < adj[node].size(); i++){
            int nweight = -adj[node][i].first;
            int nnode = adj[node][i].second;
            if(!visited[nnode]) pq.push(pi(-(weight + nweight), nnode));
        }
    }
}

void init(){
    cin >> N >> E;
    for(int i = 0 ; i <= N ; i++)
        for(int j = 0 ; j < 3 ; j++)
            dist[i][j] = INF;
    for(int i = 0 ; i < E ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pi(-c, b));
        adj[b].push_back(pi(-c, a));
    }
    cin >> v1 >> v2;
}

void solve(){
    int start[3] = {1, v1, v2};
    for(int i = 0 ; i < 3 ; i++){
        memset(visited, 0, sizeof(visited));
        dijk(start[i], i);
    }

    ans = min({dist[v1][0] + dist[v2][1] + dist[N][2], dist[v2][0] + dist[N][1] + dist[v1][2]});
    if(ans < 1 || ans > 200000000){
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
    /* cout << "\n";
    for(int i = 0 ; i <= N ; i++){
        for(int j = 0; j < 3 ; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    } */
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
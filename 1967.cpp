#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 10001;

vector<pi> adj[MAXN];
int dist[MAXN];
int N;
pi ans;

pi dijk(int root){
    pi maxnode = pi(0, root);
    priority_queue<pi> pq;
    pq.push(pi(0, root));
    while(!pq.empty()){
        int weight = pq.top().first, node = pq.top().second;
        if(weight > maxnode.first) maxnode = pq.top();
        pq.pop();
        dist[node] = weight;
        for(auto _adj: adj[node]){
            int nweight = _adj.first, nnode = _adj.second;
            if(dist[nnode] == -1) pq.push(pi(weight + nweight, nnode));
        }
    }
    return maxnode;
}

void init(){
    cin >> N;
    for(int i = 1 ; i < N ; i++){
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj[n1].push_back(pi(weight, n2));
        adj[n2].push_back(pi(weight, n1));
    }
}

void solve(){
    memset(dist, -1, sizeof(dist));
    pi far = dijk(1);
    memset(dist, -1, sizeof(dist));
    ans = dijk(far.second);
    cout << ans.first << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
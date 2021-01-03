#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<pi> edges[20001];
int V, E, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> V >> E >> K;
    for(int i = 0 ; i < E ; i++){
        //1 ~ V
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(pi(v,w));
    }
    
    //priority queue <dist, node> 
    vector<int> dist(20001, 987654321);
    dist[K] = 0;
    priority_queue<pi> pq;
    pq.push(pi(0, K));
    while(pq.size() > 0){
        //visit
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        //find adj node
        for(auto edge: edges[v]){
            int nv = edge.first, nw = edge.second;
            if(w + nw < dist[nv]){
                dist[nv] = w + nw;
                pq.push(pi(-dist[nv], nv));
            }
        }
    }

    for(int i = 1 ; i <= V ; i++){
        if(dist[i] == 987654321) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}
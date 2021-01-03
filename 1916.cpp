#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;
const int INF = 987654321;

int dist[1001];
vector<pi> edges[1001];
int N, M;
int S, E;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0 ; i <= 1000 ; i++){
        dist[i] = INF;
    }
    cin >> N >> M;
    while(M--){
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back(pi(-weight, to));
    }
    cin >> S >> E;
}

void solve(){
    //-weight, to
    priority_queue<pi> pq;
    pq.push(pi(0, S));
    while(!pq.empty()){
        int weight = pq.top().first;
        int to = pq.top().second;
        pq.pop();
        dist[to] = -weight;
        if(to == E){
            cout << dist[to] << "\n";
            return;
        }
        for(auto edge: edges[to]){
            if(dist[edge.second] == INF){
                pq.push(pi(edge.first + weight, edge.second));
            }
        }
    }
}

int main(){
    init();
    solve();
}
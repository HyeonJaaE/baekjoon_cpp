#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;
using ll = long long;

const int MAXV = 1001;
vector<vector<pi>> tree(MAXV);
ll weights[MAXV];
int Visit[MAXV];
ll max_weight = -1;
int max_node = -1;
int V;

void DFS(int root){
    Visit[root] = 1;
    for(auto t: tree[root]){
        if(Visit[t.first] == 0){
            weights[t.first] = weights[root] + t.second;
            if(weights[t.first] > max_weight){
                max_weight = weights[t.first];
                max_node = t.first;
            }
            DFS(t.first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> V;
    for(int i = 0 ; i < V; i++){
        int e1; cin >> e1;
        while(true){
            int e2; cin >> e2;
            if(e2 == -1) break;
            int w; cin >> w;
            tree[e1].push_back(pi(e2, w));
        }
    }
    
    memset(Visit, 0, sizeof(Visit));
    memset(weights, 0, sizeof(weights));
    DFS(1);
    int nroot = max_node;

    memset(Visit, 0, sizeof(Visit));
    memset(weights, 0, sizeof(weights));
    max_weight = -1;
    max_node = -1;
    DFS(nroot);
    cout << max_weight << "\n";
}
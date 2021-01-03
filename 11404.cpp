#define FOR(i,n) for(int i = 1 ; i <= n ; i++)

#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
int edges[101][101];
int n, m;

void init(){
    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(i == j){
                edges[i][j] = 0;
            } else {
                edges[i][j] = INF;
            }
        }
    }
    while(m--){
        int from, to, dist;
        cin >> from >> to >> dist;
        if(edges[from][to] == INF){
            edges[from][to] = dist;
        } else {
            edges[from][to] = min(edges[from][to], dist);
        }
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                if(edges[k][j] > edges[k][i] + edges[i][j] )
                    edges[k][j] = edges[k][i] + edges[i][j];
            }
        }
    }
    FOR(i, n){
        FOR(j, n){
            if(edges[i][j] == INF){
                cout << 0 << " ";
            } else {
                cout << edges[i][j] << " ";
            }
        }
        cout << "\n";
    }    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
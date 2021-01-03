#include<bits/stdc++.h>
using namespace std;

int DP[1001];
int buildTime[1001];
vector<int> buildOrder[1001];
int Visit[1001];
int T, N, K, W;

void DFS(int node){
    for(auto order: buildOrder[node]){
        if(Visit[order] == 0){
            Visit[order] = 1;
            DFS(order);
        }
    }

    if(buildOrder[node].size() == 0){
        DP[node] = buildTime[node];
    } else {
        int maxTime = -1;
        for(auto order: buildOrder[node]){
            maxTime = max(maxTime, DP[order]);
        }
        DP[node] = buildTime[node] + maxTime;
    }
}

void init(){
    cin >> N >> K;
    memset(buildTime, 0, sizeof(buildTime));
    memset(Visit, 0, sizeof(Visit));
    for(int i = 0 ; i <= N ; i++) buildOrder[i].clear();
    
    for(int i = 1 ; i <= N ; i++)
        cin >> buildTime[i];
    
    for(int i = 0 ; i < K ; i++){
        int X, Y; cin >> X >> Y;
        buildOrder[Y].push_back(X);
    }
    cin >> W;
}

void solve(){
    DFS(W);
    for(int i = 0 ; i <= N ; i++) cout << DP[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        init();
        solve();
    }
    return 0;
}
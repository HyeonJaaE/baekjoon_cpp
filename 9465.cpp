#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int cost[2][MAXN];
vector<int> dp;
int T, N;

void init(){
    cin >> N;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> cost[i][j];
        }
    }
    dp = {cost[0][1], cost[1][1]};
}

void solve(){
    for(int j = 2 ; j <= N ; j++){
        vector<int> ndp;
        ndp.push_back(max(dp[0], dp[1] + cost[0][j]));
        ndp.push_back(max(dp[1], dp[0] + cost[1][j]));
        dp = ndp;
    }
    cout << max(dp[0], dp[1]) << "\n";
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
}
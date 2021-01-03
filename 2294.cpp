#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 10001;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> dp(MAXN, MAXN);
    vector<int> coins;
    dp[0] = 0;

    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++){
        int coin; cin >> coin;
        coins.push_back(coin);
    }
    
    for(auto coin: coins){
        for(int i = coin; i < MAXN; i++){
            int tmp = dp[i-coin] + 1;
            dp[i] = tmp < dp[i] ? tmp : dp[i];
        }
    }

    int ans = (dp[K] == MAXN) ? -1 : dp[K];
    cout << ans << '\n';
}


#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int dp[201][201];
int N, K;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
}

void solve(){
    for(int i = 0 ; i <= N ; i++){
        dp[1][i] = 1;
    }
    for(int i = 0 ; i <= K ; i++){
        dp[i][0] = 1;
    }
    for(int i = 2 ; i <= K ; i++){
        for(int j = 1 ; j <= N ; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }
    cout << dp[K][N] << "\n";
}

int main(){
    init();
    solve();
}
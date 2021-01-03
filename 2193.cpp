#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; // 0 < N <= 90
    ll dp[91] = {0, 1, 1};
    for(int i = 3 ; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N] << "\n";
}
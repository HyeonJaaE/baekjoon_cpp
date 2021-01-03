#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    int T; cin >> T;
    int dp[12] = {0,1,2,4,};
    for(int i = 4; i < 12; i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    while(T--){
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}



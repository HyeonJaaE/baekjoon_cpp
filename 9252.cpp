#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1; cin >> s1;
    string s2; cin >> s2;
    int SZ1 = s1.size();
    int SZ2 = s2.size();
    vector<vector<string>> dp(SZ1 + 1, vector<string>(SZ2 + 1, ""));

    for(int i = 1; i <= SZ1; i++){
        for(int j = 1; j <= SZ2; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
            else dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
        }
    }
    for(auto foo: dp){
        for(auto bar: foo){
            if(bar.size()>0) cout << bar << "\t";
            else cout << "none" << "\t";
        }
        cout << "\n";
    }

    cout << dp[SZ1][SZ2].size() << "\n";
    if(dp[SZ1][SZ2].size() > 0) cout << dp[SZ1][SZ2] << "\n";
}
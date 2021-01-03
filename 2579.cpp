#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   

    int N; cin >> N;
    vector<int> stairs = {0};
    int dp[301] = {0,};
    for(int i = 0 ; i < N; i++){
        int stair; cin >> stair;
        stairs.push_back(stair);
    }

    dp[1] = stairs[1];
    if(N > 1) dp[2] = stairs[1] + stairs[2];
    for(int i = 3 ; i < stairs.size(); i++){
        dp[i] = max({dp[i-3] + stairs[i] + stairs[i-1], dp[i-2] + stairs[i]});
    }
    cout << dp[N] << "\n";
}
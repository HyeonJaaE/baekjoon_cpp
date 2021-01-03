#include <bits/stdc++.h>
using namespace std;

vector<int> S;
int dp[1001], dp_reverse[1001];
int N;
int ans = -1;

void getDP(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(S[j] < S[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    for(int i = N ; i > 0 ; i--){
        for(int j = N; j > i ; j--){
            if(S[j] < S[i]){
                dp_reverse[i] = max(dp_reverse[j] + 1 , dp_reverse[i]);
            }
        }
    }
}

int main(){
    cin >> N;
    memset(dp, 0, sizeof(dp));
    memset(dp_reverse, 0, sizeof(dp_reverse));
    S.push_back(0);
    for(int i = 1 ; i <= N ; i++){
        int n; cin >> n;
        S.push_back(n);
    }
    getDP();
    
    for(int i = 0 ; i <= N ; i++){
        cout << dp[i] << " ";
    }
    cout << "\n";
    for(int i = 0 ; i <= N ; i++){
        cout << dp_reverse[i] << " ";
    }
    cout << "\n";

    for(int i = 0 ; i <= N ; i++){
        ans = max(ans, dp[i] + dp_reverse[i]);
    }

    cout << ans << "\n";
}
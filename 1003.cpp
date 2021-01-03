#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    int dp0[41] = {1,0,1,1};
    int dp1[41] = {0,1,1,2};

    for(int i = 4; i < 41; i++){
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    while(T--){
        int N; cin >> N;
        cout << dp0[N] << " " << dp1[N] << "\n";
    }
}
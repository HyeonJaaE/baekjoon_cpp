#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;
using ll = long long;

ll dp[100][21];
int nums[100];
int N;

int DP(int node, int cur){
    if(cur < 0 || cur > 20) return 0;
    ll &ret = dp[node][cur];
    if(node == 1) return ret;
    if(ret == 0)
        return dp[node][cur] = DP(node - 1, cur - nums[node - 1]) + DP(node - 1, cur + nums[node - 1]);
    return ret;
}

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> nums[i];
}

void solve(){
    dp[1][nums[0]] = 1;
    cout << DP(N - 1, nums[N-1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
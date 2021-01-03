#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 2001;
int dp[MAXN][MAXN];
int nums[MAXN];
int N, M;

int DP(int s, int e){
    if(s == e || s > e) return 1;
    int &ret = dp[s][e];
    if(ret == -1){
        if(nums[s] == nums[e]){
            ret = DP(s+1, e-1);
        } else {
            ret = 0;
        }
    }
    return ret;
}

void init(){
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> nums[i];
    }
    cin >> M;
}

void solve(){
    for(int i = 0 ; i < M ; i++){
        int S, E;
        cin >> S >> E;
        cout << DP(S,E) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}

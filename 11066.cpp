#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXK = 501;

int dp[MAXK][MAXK];
int sum[MAXK];
int files[MAXK];
int T, K;

int merge(int i, int j){
    if(i == j) return 0;
    int &ret = dp[i][j];
    if(ret == -1){
        for(int pos = i ; pos < j ; pos++){
            int tmp = merge(i, pos) + merge(pos + 1, j) + sum[j] - sum[i-1];
            if(ret == -1 || tmp < ret ) ret = tmp;
        }
    }
    return ret;
}

void init(){
    memset(files, 0, sizeof(files));
    memset(dp, -1, sizeof(dp));
    cin >> K;
    for(int i = 1 ; i <= K ; i++) {
        cin >> files[i];
        sum[i] = files[i] + sum[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    cout.tie(0);
    cin >> T;
    while(T--){
        init();
        cout << merge(1, K) << "\n";
    }
    return 0;
}
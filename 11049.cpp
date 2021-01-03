#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int MAXN = 501;

vector<pi> matrix;
int dp[MAXN][MAXN];
int N;

int merge(int i, int j){
    if(i == j) return 0;
    int &ret = dp[i][j];
    if(ret == -1){
        for(int pos = i ; pos < j ; pos++){
            int tmp = merge(i, pos) + merge(pos + 1, j) + (matrix[i].first * matrix[pos].second * matrix[j].second);
            if(ret == -1 || ret > tmp) ret = tmp;
        }
    }
    return ret;
}

void init(){
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int r, c;
        cin >> r >> c;
        matrix.push_back(pi(r,c));
    }
}

void solve(){
    cout << merge(0, N - 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
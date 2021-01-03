#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dp[1001][1001];
vector<string> board;
int N, M;

int ans = 0;

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        string s; cin >> s;
        board.push_back(s);
    }
}

void solve(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(board[i-1][j-1] == '1'){
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ans * ans << "\n";   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
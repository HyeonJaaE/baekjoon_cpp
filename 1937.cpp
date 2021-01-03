#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 500;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int dp[MAXN][MAXN];
int board[MAXN][MAXN];
int N;

int ans = 0;

int DFS(int y, int x){
    if(dp[y][x]) return dp[y][x];
    dp[y][x] = 1;

    for(int d = 0 ; d < 4 ; d++){
        int ny = y + dy[d], nx = x + dx[d];
        if(0 <= ny && ny < N && 0 <= nx && nx < N && board[ny][nx] > board[y][x])
            dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);
    }
    return dp[y][x];
}

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> board[i][j];
}

void solve(){
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            ans = max(ans, DFS(i, j));

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
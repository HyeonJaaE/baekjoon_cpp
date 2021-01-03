#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int n, m;
int board[500][500];
int ans = -1;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(pi parent, pi loc, int sum, int depth){
    int y = loc.first;
    int x = loc.second;
    sum += board[y][x];
    if(depth == 4){
        ans = max(sum, ans);
        return; 
    }
    for(int d = 0 ; d < 4 ; d++){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(0 <= ny && ny < n && 0 <= nx && nx < m && pi(ny, nx) != parent){
            DFS(pi(y,x), pi(ny, nx), sum, depth + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    memset(board, 0, sizeof(board));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            DFS(pi(i,j), pi(i,j), 0, 1);

            // ㅗ ㅏ ㅜ ㅓ shape check
            int num = board[i][j];
            int l = -1000;
            int r = -1000;
            int u = -1000;
            int d = -1000;
            if(j - 1 >= 0) l = board[i][j-1];
            if(j + 1 < m) r = board[i][j+1];
            if(i - 1 >= 0) u = board[i-1][j];
            if(i + 1 < n) d = board[i+1][j];
            
            ans = max(ans, num + u + r + d);
            ans = max(ans, num + r + d + l);
            ans = max(ans, num + d + l + u);
            ans = max(ans, num + l + u + r);
        }
    }
    cout << ans << "\n";
}
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 500;
int ans = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int board[MAXN][MAXN];
int cnt[MAXN][MAXN];
int Visit[MAXN][MAXN];
int N, M;

int DFS(int y, int x){
    if(y == N - 1 && x == M - 1) return 1;
    Visit[y][x] = 1;

    for(int d = 0 ; d < 4 ; d++){
        int ny = y + dy[d], nx = x + dx[d];
        if(0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] < board[y][x]){
            if(cnt[ny][nx] == 0 && Visit[ny][nx] == 0){
                cnt[y][x] += DFS(ny, nx);
            } else {
                cnt[y][x] += cnt[ny][nx];
            }
        }
    }

    return cnt[y][x];
}

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
        }
    }
}

void solve(){
    memset(cnt, 0, sizeof(cnt));
    memset(Visit, 0, sizeof(cnt));
    cout << DFS(0, 0) << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<string> board(50);
int visited[50][50];
int R, C;

int ans = 0;

void BFS(int sy, int sx){
    visited[sy][sx] = 0;
    queue<pi> q;
    q.push(pi(sy, sx));
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        ans = max(ans, visited[y][x]);
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < R && 0 <= nx && nx < C && board[ny][nx] == 'L'){
                if(visited[ny][nx] == -1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push(pi(ny, nx));
                }
            }
        }
    }
}

void init(){
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++) 
        cin >> board[i];
}

void solve(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] == 'L'){
                BFS(i, j);
                memset(visited, -1, sizeof(visited));
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int board[50][50];
int N, M;
int r, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // d => 0, 1, 2, 3 = 북, 동, 남, 서
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
        }
    }
    //1 wall, 2 cleaned
    queue<pi> q;
    q.push(pi(r,c));
    int cnt = 0;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        if(board[y][x] == 0){
            board[y][x] = 2;
            cnt += 1;
        }
        
        /* int foo; cin >> foo;
        cout << y << "," << x << " d : " << d << "\n";
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        } */

        int moved = 0;
        for(int i = 1 ; i <= 4 ; i++){
            //turn left
            d = (d - 1) % 4;
            if(d < 0) d += 4;
            int ny = y + dy[d], nx = x + dx[d];
            if(0<=ny&&ny<N&&0<=nx&&nx<M && board[ny][nx] == 0){
                moved = 1;
                q.push(pi(ny,nx));
                break;
            }
        }

        if(moved == 0){
            //move back
            int nd = (d + 2) % 4;
            int ny = y + dy[nd], nx = x + dx[nd];
            if(0<=ny&&ny<N&&0<=nx&&nx<M&&board[ny][nx] != 1){
                q.push(pi(ny, nx));
            }
        }
    }
    cout << cnt << "\n";
}
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = INF;

vector<string> board(1000);
int Visit[1000][1000][2];
int N, M;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    memset(Visit, 0, sizeof(Visit));
}

void solve(){
    //(y,x),(count wall, dist)
    queue<pair<pi,pi>> q;
    q.push(make_pair(pi(0,0),pi(0,1)));
    Visit[0][0][0] = 1;
    while(!q.empty()){
        int y = q.front().first.first, x = q.front().first.second;
        int wallcnt = q.front().second.first, dist = q.front().second.second;
        q.pop();

        if(y == N - 1 && x == M - 1){
            cout << dist << "\n";
            return;
        }

        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < N && 0 <= nx && nx < M){
                if(board[ny][nx] == '1' && wallcnt == 0){
                    Visit[ny][nx][1] = 1;
                    q.push(make_pair(pi(ny, nx), pi(1, dist + 1)));
                } else if(board[ny][nx] == '0' && Visit[ny][nx][wallcnt] == 0){
                    Visit[ny][nx][wallcnt] = 1;
                    q.push(make_pair(pi(ny, nx), pi(wallcnt, dist + 1)));
                }
            }
        }
        //cout << "loc : " << y << "," << x << " w, d : " << wallcnt << " , " << dist << "\n";
    }
    cout << -1 << "\n";
    return;
}

int main(){
    init();
    solve();
}


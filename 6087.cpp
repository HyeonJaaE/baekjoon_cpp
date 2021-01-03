#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXH = 100;
vector<pi> path[MAXH][MAXH];
vector<string> board(MAXH);
vector<pi> loc;
int v[MAXH][MAXH];
int cnt[MAXH][MAXH];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int W, H;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> W >> H;
    for(int i = 0 ; i < H ; i++){
        cin >> board[i];
        for(int j = 0 ; j < W ; j++){
            if(board[i][j] == 'C') loc.push_back(pi(i,j));
        }
    }
    
    memset(v, 0, sizeof(v));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W; j++){
            cnt[i][j] = 987654321;
        }
    }
    path[loc[0].first][loc[0].second] = {loc[0]};
    v[loc[0].first][loc[0].second] = 0;
    cnt[loc[0].first][loc[0].second] = 0;
    queue<pi> q;
    q.push(loc[0]);
    while(q.size() > 0){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < H && 0 <= nx && nx < W && board[ny][nx] != '*'){
                if(v[ny][nx] == 0){
                    v[ny][nx] = 1;
                    q.push(pi(ny,nx));
                }
                if(cnt[ny][nx] > cnt[y][x] + 1){
                    vector<pi> npath = path[y][x];
                    npath.push_back(pi(ny,nx));
                    path[ny][nx] = npath;
                    cnt[ny][nx] = cnt[y][x] + 1;
                }
            }
        }
    }

    /*
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if( cnt[i][j] == 987654321){
                cout << 0 << "\t";
            } else {
                cout << cnt[i][j] << "\t";
            }
        }
        cout << "\n";
    }

    */
    
    int a, b; cin >> a >> b;
    for(auto foo: path[a][b]){
        cout << foo.first << "," << foo.second << " ";
    }
    cout << "\n";

    
    
    vector<pi> &p = path[loc[1].first][loc[1].second];
    pi dir;
    int mirror = 0;
    for(int i = 1 ; i < p.size(); i++){
        pi move = pi(abs(p[i-1].first - p[i].first), abs(p[i-1].second - p[i].second));
        cout << move.first << "," << move.second << " ";
        if( i != 1 ){
            if( move != dir ){
                mirror += 1;
            }
        }
        dir = move;
    }
    cout << "\n";
    cout << mirror << "\n";
}
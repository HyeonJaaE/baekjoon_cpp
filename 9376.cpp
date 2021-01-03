#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 100;
const int INF = 987654321;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T; cin >> T;
    while(T--){
        int h, w; cin >> h >> w;
        int cnt[MAXN][MAXN];
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w; j ++){
                cnt[i][j] = INF;
            }
        }
        vector<pi> memo[MAXN][MAXN];
        vector<string> board(MAXN);
        for(int i = 0 ; i < h ; i++) cin >> board[i];
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(board[i][j] == '$'){
                    deque<pi> q;
                    q.push(pi(i,j));
                    cnt[i][j] = 0;
                    while(q.size()){
                        pi loc = q.front(); q.pop();
                        int y = loc.first;
                        int x = loc.second;
                        for(int d = 0 ; d < 4 ; d++){
                            int ny = y + dy[d];
                            int nx = x + dx[d];
                            if(0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] != '*'){
                                if(cnt[ny][nx] == INF) q.push(pi(ny,nx));
                                if(board[ny][nx] == '#') cnt[ny][nx] = min(cnt[ny][nx], cnt[y][x] + 1);
                                else cnt[ny][nx] = cnt[y][x];
                            }
                        }
                    }
                    break;
                }
            }
        }
    
        for(int _i = 0 ; _i < h ; _i++){
            for(int _j = 0 ; _j < w ; _j++){
                if(cnt[_i][_j] == INF) cout << setw(2) << '-' << " ";
                else cout << setw(2) << cnt[_i][_j] << " ";
            }
            cout << "\n";
        }
    }
}
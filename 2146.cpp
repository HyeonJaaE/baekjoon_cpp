#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
const int MAXN = 100;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0 ,-1};

int group[MAXN][MAXN];
int board[MAXN][MAXN];
int dist[MAXN][MAXN];
int N;

int groupCnt = 0;
int ans = INF;

void bridge(int i, int j){
    memset(dist, 0, sizeof(dist));
    queue<pi> q;
    q.push(pi(i,j));
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < N && 0 <= nx && nx < N){
                if(group[i][j] == group[ny][nx]){
                    //같은 대륙
                    continue;
                } else if(group[ny][nx] != 0){
                    //다른 대륙
                    ans = min(ans, dist[y][x]);
                    continue;
                }

                if(dist[ny][nx] == 0){
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(pi(ny, nx));
                }
            }
        }
    }
}

void grouping(int i, int j){
    queue<pi> q;
    q.push(pi(i,j));
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(board[ny][nx] == 0) continue;
            if(!group[ny][nx]){
                group[ny][nx] = groupCnt;
                q.push(pi(ny,nx));
            }
        }
    }
}

void init(){
    memset(group, 0, sizeof(group));
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> board[i][j];
}

void solve(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 1 && !group[i][j]){
                groupCnt += 1;
                group[i][j] = groupCnt;
                grouping(i, j);
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 1)
                bridge(i, j);
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
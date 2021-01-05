#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
const int MAXN = 50;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<pi> virus;
vector<int> virus_order;
int board[MAXN][MAXN];
int visited[MAXN][MAXN];
int N, M;

int wall = 0;
int ans = INF;

void BFS(){
    int cnt = 0;
    int virus_cnt = 0;
    queue<pi> q;
    for(auto order: virus_order){
        q.push(pi(virus[order]));
        visited[virus[order].first][virus[order].second] = 0;
    }

    while(!q.empty()){
        virus_cnt += 1;
        int y = q.front().first, x = q.front().second;
        q.pop();
        if(board[y][x] == 0) cnt = max(visited[y][x], cnt);
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(board[ny][nx] == 1) continue;
            if(visited[ny][nx] == -1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push(pi(ny,nx));
            }
        }
    }

    if((N*N) - wall == virus_cnt){
        ans = min(cnt, ans);
    }
}

void get_virus_order(int cur){
    if(virus_order.size() == M){
        memset(visited, -1, sizeof(visited));
        BFS();
        return;    
    }

    for(int i = cur ; i < virus.size() ; i++){
        virus_order.push_back(i);
        get_virus_order(i + 1);
        virus_order.pop_back();
    }  
}

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back(pi(i,j));
            if(board[i][j] == 1) wall += 1;
        }
    }
}

void solve(){
    get_virus_order(0);
    if( ans == INF ) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
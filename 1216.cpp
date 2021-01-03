#define FOR(i, n) for(int i = 0 ; i < n ; i++)

#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int Visit[100][100];
vector<string> board;
int M, N;


void BFS(){
    //Visit = 부순 벽 갯수
    queue<pi> q;
    q.push(pi(0,0));
    Visit[0][0] = 0;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < N && 0 <= nx && nx < M ){
                if(board[ny][nx] == '1'){
                    if(Visit[ny][nx] > Visit[y][x] + 1){
                        Visit[ny][nx] = Visit[y][x] + 1;
                        q.push(pi(ny,nx));
                    }
                } else {
                    if(Visit[ny][nx] > Visit[y][x]){
                        Visit[ny][nx] = Visit[y][x];
                        q.push(pi(ny,nx));
                    }
                }
            }
        }
    }
}
void init(){
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
            string s; cin >> s;
            board.push_back(s);
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            Visit[i][j] = INF;
        }
    }

}

void solve(){
    BFS();
    cout << Visit[N-1][M-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
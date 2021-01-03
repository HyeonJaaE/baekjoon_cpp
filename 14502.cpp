#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, M;
int board[8][8];
int n_board[8][8];
vector<pi> blank;
vector<pi> virus;
vector<pi> walls;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;

void getBoard(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            n_board[i][j] = board[i][j];
        }
    }
}

int BFS(){
    int cnt = 0;
    for(auto v: virus){
        cnt += 1;
        queue<pi> q;
        q.push(pi(v.first, v.second));
        while(q.size() > 0){
            int y = q.front().first, x = q.front().second;
            q.pop();
            for(int d = 0 ; d < 4 ; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(0<=ny&&ny<N&&0<=nx&&nx<M&&n_board[ny][nx] == 0){
                    n_board[ny][nx] = 2;
                    cnt += 1;
                    q.push(pi(ny, nx));
                }
            }
        }
    }
    return (N * M) - walls.size() - cnt -3;
}

void DFS(int root, vector<int> wall){
    if(wall.size() == 3){
        getBoard();
        int cnt = 0;
        for(auto w: wall){
            n_board[blank[w].first][blank[w].second] = 1;
        }
        cnt = BFS();
        ans = max(cnt, ans);
        return;
    }

    for(int i = root ; i < blank.size(); i++){
        vector<int> n_wall = wall;
        n_wall.push_back(i);
        DFS(i + 1, n_wall);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    memset(board, 0, sizeof(board));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) blank.push_back(pi(i, j));
            if(board[i][j] == 1) walls.push_back(pi(i, j));
            if(board[i][j] == 2) virus.push_back(pi(i, j));
        }
    }
    DFS(0, {});
    cout << ans << "\n";
}
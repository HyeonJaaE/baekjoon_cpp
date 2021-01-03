#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 15;
deque<vector<int>> board(MAXN, vector<int>(MAXN, 0));
deque<vector<int>> tmp_board(MAXN);
vector<int> n_board(MAXN);
int n, m, d;
int dy[3] = {0, -1, 0};
int dx[3] = {-1, 0, 1};
int ans = -1;


pi shoot(int loc){
    int v[MAXN][MAXN];
    memset(v, 0, sizeof(v));
    int depth = 0;
    queue<vector<pi>> q;
    q.push(vector<pi>(1, pi(n-1, loc)));
    v[n-1][loc] = 1;
    while(q.size() > 0 && depth++ < d){
        vector<pi> _q = q.front(); q.pop();
        vector<pi> nq;
        for(auto aim: _q){
            int y = aim.first;
            int x = aim.second;
            if(tmp_board[y][x] == 1){
                return pi(y,x);
            }
            //search left, up, right
            for(int i = 0; i < 3; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < m && v[ny][nx] == 0){
                    v[ny][nx] = 1;
                    nq.push_back(pi(ny,nx));
                }
            }
        }
        q.push(nq);
    }
    return pi(-1,-1);
}

int game(vector<int> archers){
    int kill = 0;
    vector<pi> targets;
    for(auto loc: archers){
        targets.push_back(shoot(loc));
    }
    
    for(auto target: targets){
        if(target == pi(-1,-1)) continue;
        int ty = target.first;
        int tx = target.second;
        if(tmp_board[ty][tx] == 1){
            tmp_board[ty][tx] = 0;
            kill += 1;
        }
    }
    return kill;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0 ; i < m; i++){
        for(int j = i + 1 ; j < m; j ++){
            for(int k = j + 1 ; k < m ; k ++){
                vector<int> archers = {i, j, k};
                tmp_board = board;
                int kill = 0;
                int rotate = n;
                while(rotate--){
                    kill += game(archers);
                    tmp_board.pop_back();
                    tmp_board.push_front(n_board);
                }
                ans = max(kill, ans);
            }
        }
    }
    cout << ans << "\n";
}
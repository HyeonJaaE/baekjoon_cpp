#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 150;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int board[MAXN][MAXN];
int cntboard[MAXN][MAXN];
int R, C;

void BFS(pi parent){
    queue<pi> q;
    q.push(parent);
    while(q.size() > 0){
        pi rc = q.front(); q.pop();
        int r = rc.first, c = rc.second;
        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(0<= nr && nr < R && 0<= nc && nc < C){
                if(board[nr][nc] == -1){
                    q.push(pi(nr,nc));
                    if(cntboard[nr][nc] == 0){
                        //방문하지 않은 물
                        board[nr][nc] = board[r][c];
                    } else {
                        //방문하지 않은 빙판
                        board[nr][nc] = max(cntboard[nr][nc], board[r][c]);
                    }
                } else {
                    if(cntboard[nr][nc] == 0){
                        //방문했던 물
                        board[nr][nc] = min(board[r][c], board[nr][nc]);
                    } else {
                        board[nr][nc] = max( min(board[r][c], board[nr][nc]), cntboard[nr][nc] );
                    }
                }
            }
        }
        
        

        cout << "\n";
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C ; j++){
                cout << board[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> R >> C;
    vector<pi> loc;
    vector<pi> checkli;
    memset(board, 0, sizeof(board));
    memset(cntboard, 0, sizeof(cntboard));

    for(int i = 0 ; i < R ; i++){
        string info; cin >> info;
        for(int j = 0 ; j < info.size() ; j++){
            if(info[j] == 'L'){
                loc.push_back(pi(i, j));
            }

            if(info[j] == 'X'){
                checkli.push_back(pi(i,j));
                board[i][j] = 1;
            } else{
                board[i][j] = -1;
            }
        }
    }
    
    int cnt = 1;
    while(checkli.size() > 0){
        vector<pi> ncheckli;
        for(auto cl: checkli){
            int r = cl.first, c = cl.second;
            int melt = 0;
            for(int d = 0; d < 4; d++){
                int nr = r + dr[d], nc = c + dc[d];
                if(0 <= nr && nr < R && 0 <= nc && nc < C && board[nr][nc] == -1 && cntboard[nr][nc] != cnt){
                    board[r][c] = -1;
                    cntboard[r][c] = cnt;
                    melt = 1;
                    break;
                }
            }
            if(melt == 0) ncheckli.push_back(cl);
        }
        cnt += 1;
        checkli = ncheckli;
    }

    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C ; j++){
            cout << cntboard[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }


    pi start = loc[0], end = loc[1];
    board[start.first][start.second] = 0;
    BFS(start);
    cout << board[end.first][end.second] << "\n";

}

/*
0 0 0 1 2 3 3 2 1 0 0 1 1 0 1 2 2 
0 0 0 0 1 2 3 2 2 1 1 2 1 0 1 1 1
0 0 0 1 2 3 2 1 1 2 2 3 2 1 1 0 0
0 0 1 2 3 2 1 0 0 1 2 3 3 2 1 0 0
0 1 2 3 3 2 1 0 0 1 2 3 3 2 1 0 0
1 1 2 2 3 2 1 0 0 0 1 2 2 1 0 0 0
0 0 1 1 2 2 1 0 0 0 1 2 1 0 0 0 0
0 0 0 0 1 2 2 1 1 0 1 2 1 0 0 0 0
*/
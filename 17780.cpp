#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 14;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
char dir[4] = {'r', 'l', 'u', 'd'};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<vector<int>> board(N + 2, vector<int>(N + 2, 0));
    vector<pi> boardv[MAXN][MAXN];
    pi loc[MAXN];
    
    for(int i = 0; i < N + 2; i++){
        board[0][i] = 2;
        board[N+1][i] = 2;
    }
    for(int i = 1; i < N + 1; i++){
        board[i][0] = 2;
        board[i][N+1] = 2;
    }
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            cin >> board[i][j];
        }
    }
    // 우 좌 상 하
    for(int i = 0; i < K; i++){
        int r, c, d; cin >> r >> c >> d;
        boardv[r][c].push_back(make_pair(i, d - 1));
        loc[i] = make_pair(r,c);
    }
    /*
    for(int i = 0 ; i < N + 2; i++){
        for(int j = 0 ; j < N + 2; j++){
            if(boardv[i][j].size() > 0){
                for(auto foo: boardv[i][j]) cout << foo.first << "," << dir[foo.second] << " ";
            } 
            cout << "/\t";
        }
        cout << "\n";
    }
    cout << "\n";
    */

    int cnt = 0;
    while(true){
        cnt += 1;
        for(int i = 0; i < K; i++){
            int r = loc[i].first;
            int c = loc[i].second;
            //가장 밑에 위치한 말만 이동 가능
            vector<pi> &bv = boardv[r][c];
            if(bv[0].first == i){

                int nr = r + dr[bv[0].second];
                int nc = c + dc[bv[0].second];
                
                //바깥 or 파랑
                if(board[nr][nc] == 2){
                    pi &b = bv[0];
                    if(b.second == 0) b.second = 1;
                    else if(b.second == 1) b.second = 0;
                    else if(b.second == 2) b.second = 3;
                    else if(b.second == 3) b.second = 2;
                    nr = r + dr[bv[0].second];
                    nc = c + dc[bv[0].second];
                } 

                if(board[nr][nc] != 2){
                    if(board[nr][nc] == 1) reverse(bv.begin(), bv.end());
                    for(auto foo: bv) loc[foo.first] = make_pair(nr, nc);
                    boardv[nr][nc].insert(boardv[nr][nc].end(), bv.begin(), bv.end());
                    bv.clear();
                }
                
                if(boardv[nr][nc].size() >= 4){
                    cout << cnt << "\n";
                    return 0;
                }
            }
        }
        if(cnt >= 1000){
            cout << -1 << "\n";
            return 0;
        }
    }
}
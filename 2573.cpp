#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pi> ice;
int Visit[300][300];
vector<vector<int>> board(300, vector<int>(300, 0));
int R, C;

int year = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x, int g){
    Visit[y][x] = g;
    for(int d = 0 ; d < 4 ; d++){
        int ny = y + dy[d], nx = x + dx[d];
        if(0 <= ny && ny < R && 0 <= nx && nx < C && Visit[ny][nx] == 0 && board[ny][nx] != 0){
            DFS(ny, nx, g);
        }
    }
}

void melt(){
    vector<vector<int>> nboard = board;
    for(auto _ice: ice){
        int y = _ice.first, x = _ice.second;
        int adjWater = 0;
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < R && 0 <= nx && nx < C && board[ny][nx] == 0)
                adjWater += 1;
        }
        nboard[y][x] -= adjWater;
        if(nboard[y][x] < 0) nboard[y][x] = 0;
    }
    board = nboard;
}

int check_group(){
    int group = 0;
    memset(Visit, 0, sizeof(Visit));
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] != 0 && Visit[i][j] == 0){
                group += 1;
                DFS(i,j,group);
            }
        }
    }
    return group;
}

void init(){
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> board[i][j];
            if(board[i][j] != 0){
               ice.push_back(pi(i,j));
            }
        }
    }
}

void solve(){
    while(true){
        year += 1;
        melt();
        int cnt = check_group();
        if(cnt == 0) {
            year = 0;
            break;
        } else if(cnt > 1){
            break;
        }
    }
    cout << year << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
}
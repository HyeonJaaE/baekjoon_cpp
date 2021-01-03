#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int Visit[50][50];
queue<pi> q;
vector<string> board;
int R, C;
pi S, D;

//* 물, X 돌, S 고슴도치, D 굴
//물 한번 차고 고슴 도치 이동 한번 하고

void flood(){
    vector<string> nboard = board;
    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] == '*'){
                for(int d = 0 ; d < 4 ; d++){
                    int ny = i + dy[d], nx = j + dx[d];
                    if(0 <= ny && ny < R && 0 <= nx && nx < C && board[ny][nx] == '.'){
                        nboard[ny][nx] = '*';
                    }
                }
            }
        }
    }
    board = nboard;
}

void BFS(){
    queue<pi> nq;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < R && 0 <= nx && nx < C && (board[ny][nx] == '.' || pi(ny, nx) == D) && Visit[ny][nx] == -1){
                Visit[ny][nx] = Visit[y][x] + 1;
                nq.push(pi(ny,nx));
            }
        }
    }
    q = nq;
}

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        string s; cin >> s;
        board.push_back(s);
    }
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] == 'S'){
                S = pi(i,j);
                board[i][j] = '.';
            } else if(board[i][j] == 'D'){
                D = pi(i,j);
            }
        }
    }
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            Visit[i][j] = -1;
    Visit[S.first][S.second] = 0;
    q.push(S);
}

void solve(){
    while(!q.empty()){
        flood();
        BFS();
    }
    if(Visit[D.first][D.second] == -1){
        cout << "KAKTUS\n";
    } else {
        cout << Visit[D.first][D.second] << "\n";
    }
}

int main(){
    init();
    solve();
}
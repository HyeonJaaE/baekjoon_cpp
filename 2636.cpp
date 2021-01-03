#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXRC = 100;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int board[MAXRC][MAXRC];
int visited[MAXRC][MAXRC];
int R, C;

int cheese = 0;
int year = 0;

void BFS(pi root){
    queue<pi> q;
    q.push(root);
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(board[ny][nx] == 1 || visited[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            q.push(pi(ny, nx));
        }
    }
}

void init(){
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) cheese += 1;
        }
    }
}

void solve(){
    while(true){
        year += 1;
        memset(visited, 0, sizeof(visited));
        visited[0][0] = 1;
        BFS(pi(0,0));
        int beforeMelt = cheese;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(board[i][j] == 0) continue;
                for(int d = 0 ; d < 4 ; d++){   
                    int ni = i + dy[d], nj = j + dx[d];
                    if(visited[ni][nj] == 1){
                        cheese -= 1;
                        board[i][j] = 0;
                        break;
                    }
                }
            }
        }

        if(cheese == 0){
            cout << year << "\n";
            cout << beforeMelt << "\n";
            return;
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
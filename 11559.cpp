#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<string> board;
int visited[12][6];
int chain = 0;

bool BFS(int i, int j){
    queue<pi> q;
    vector<pi> path;
    q.push(pi(i,j));
    path.push_back(pi(i,j));
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == board[y][x]){
                visited[ny][nx] = 1;
                q.push(pi(ny,nx));
                path.push_back(pi(ny,nx));
            }
        }
    }

    if(path.size() >= 4){
        for(auto p: path){
            int y = p.first, x = p.second;
            board[y][x] = '.';
        }
        return true;
    }
    return false;
}

void init(){
    for(int i = 0 ; i < 12 ; i++){
        string s; cin >> s;
        board.push_back(s);
    }
}

void solve(){
    while(true){
        bool boom = false;
        memset(visited, 0, sizeof(visited));
        for(int i = 0 ; i < 12 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                if(!visited[i][j] && board[i][j] != '.'){
                    visited[i][j] = 1;
                    if(BFS(i, j)) boom = true;
                }
            }
        }

        if(boom){
            chain += 1;
            vector<string> nboard(12, "......");
            for(int i = 0 ; i < 6 ; i++){
                int height = 11;
                for(int j = 11 ; j >= 0 ; j--){
                    if(board[j][i] != '.') nboard[height--][i] = board[j][i];
                }
            }
            board = nboard;
        } else {
            break;
        }

        cout << "\n";
        for(auto s: board) cout << s << "\n";
        cout << "\n";
    }
    cout << chain << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
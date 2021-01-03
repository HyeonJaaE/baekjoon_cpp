#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<string> board(100);
vector<pi> loc;
int Visit[100][100];
int w, h;
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> w >> h;
    for(int i = 0 ; i < h ; i++){
        cin >> board[i];
        for(int j = 0 ; j < w ; j ++){
            if(board[i][j] == 'C') loc.push_back(pi(i,j));
        }
    }
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            Visit[i][j] = 987654321;
        }
    }
    pi start = loc[0], end = loc[1];
    // (y, x) , (dir, cnt)
    queue<pair<pi, pi>> q;
    q.push(make_pair(start, pi(0, 0)));
    // count mirror in Visit
    Visit[start.first][start.second] = 0;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        for(int d = 1 ; d <= 4 ; d++){
            //up, right, down, left = 1, 2, 3, 4
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] != '*'){
                int ncnt = cnt;
                if(dir != d && dir != 0){
                    ncnt += 1;
                }
                if(Visit[ny][nx] >= ncnt){
                    Visit[ny][nx] = ncnt;
                    q.push(make_pair(pi(ny,nx), pi(d, ncnt)));
                }
            }
        }
    }
    cout << Visit[end.first][end.second] << "\n";
    return 0;
}
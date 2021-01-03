#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct shark{
    pi loc;
    int eatcnt = 0;
    int size = 2;
} s;
int Visit[20][20];
int board[20][20];
int curtime = 0;
int N;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    memset(board, 0, sizeof(board));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                s.loc = pi(i, j);
                board[i][j] = 0;
            }
        }
    }
}

bool BFS(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            Visit[i][j] = -1;
        }
    }
    Visit[s.loc.first][s.loc.second] = 0;
    //거리, 가장 위, 가장 왼쪽
    priority_queue<pair<int, pi>> pq;
    queue<pi> q;
    q.push(s.loc);
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();

        //먹을 수 있는 물고기
        if(board[y][x] < s.size && board[y][x] != 9 && board[y][x] != 0){
            pq.push(make_pair(-Visit[y][x], pi(-y, -x)));
        }

        for(int d = 0 ; d < 4 ; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny && ny < N && 0 <= nx && nx < N && board[ny][nx] <= s.size && Visit[ny][nx] == -1){
                Visit[ny][nx] = Visit[y][x] + 1;
                q.push(pi(ny,nx));
            }
        }
    }

    if(pq.empty()){
        return false;
    } else {
        int dist = -pq.top().first;
        int y = -pq.top().second.first;
        int x = -pq.top().second.second;
        board[y][x] = 0;
        curtime += dist;
        s.loc = pi(y, x);
        s.eatcnt += 1;
        if(s.eatcnt == s.size){
            s.size += 1;
            s.eatcnt = 0;
        }
        return true;
    }
}

void solve(){
    while(BFS());
    cout << curtime << "\n";
}

int main(){
    init();
    solve();
}
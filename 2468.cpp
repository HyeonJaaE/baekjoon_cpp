#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int board[100][100];
int visit[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N;

void DFS(int y, int x, int h){
    for(int i = 0 ; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0<=ny && ny<N && 0<=nx && nx<N && visit[ny][nx] == 0 && board[ny][nx] > h){
            visit[ny][nx] = 1;
            DFS(ny, nx, h);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(board, 0, sizeof(board));
    cin >> N;
    int maxh = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num; cin >> num;
            board[i][j] = num;
            maxh = (maxh < num) ? num : maxh;
        }
    }
    
    int ans = 0;
    for(int h = 1; h < maxh; h++){
        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N ; j++){
                if(visit[i][j] == 0 && board[i][j] > h){
                    cnt += 1;
                    visit[i][j] = 1;
                    DFS(i, j, h);
                }
            }
        }
        ans = (cnt > ans) ? cnt : ans;
    }
    cout << ans;
}
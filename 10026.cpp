#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int Visit[100][100];
int N;
vector<string> board(100);

void RGcolorweak(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 'R') board[i][j] = 'G';
        }
    }
}

int main(){
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }


    int cnt[2] = {0,};
    for(int t = 0 ; t < 2;  t++){
        memset(Visit, 0, sizeof(Visit));
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(Visit[i][j] == 0){
                    Visit[i][j] = 1;
                    cnt[t] += 1;
                    queue<pi> q;
                    q.push(pi(i,j));
                    while(!q.empty()){
                        int y = q.front().first, x = q.front().second;
                        q.pop();
                        for(int d = 0 ; d < 4 ; d++){
                            int ny = y + dy[d], nx = x + dx[d];
                            if(0 <= ny && ny < N && 0 <= nx && nx < N && board[y][x] == board[ny][nx] && Visit[ny][nx] == 0){
                                Visit[ny][nx] = 1;
                                q.push(pi(ny, nx));
                            }
                        }
                    }
                }
            }
        }
        RGcolorweak();
    }
    cout << cnt[0] << " " << cnt[1] << "\n";
}
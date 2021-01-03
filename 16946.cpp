#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAX = 100;
vector<string> board(MAX);
vector<int> group;
int Visit[MAX][MAX];
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> board[i];
    }
    memset(Visit, 0, sizeof(Visit));
    int gcnt = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == '0' && Visit[i][j] == 0){
                Visit[i][j] = gcnt;
                queue<pi> q;
                q.push(pi(i,j));
                int cnt = 1;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int d = 0 ; d < 4 ; d++){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(0 <= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == '0' && Visit[ny][nx] == 0){
                            Visit[ny][nx] = gcnt;
                            cnt += 1;
                            q.push(pi(ny,nx));
                        }
                    }
                }
                gcnt += 1;
                group.push_back(cnt);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == '1'){
                int ncnt = 1;
                set<int> group_set;
                for(int d = 0 ; d < 4 ; d++){
                    int ni = i + dy[d];
                    int nj = j + dx[d];
                    if(0 <= ni && ni < n && 0 <= nj && nj < m && Visit[ni][nj] > 0){
                        group_set.insert(Visit[ni][nj] - 1);
                    }
                }
                for(auto gs: group_set){
                    ncnt += group[gs];
                }
                cout << ncnt % 10;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}
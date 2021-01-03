#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    int R, C; cin >> R >> C;
    int board[100][100];
    memset(board, 0, sizeof(board));
    for(int i = 0 ; i < R ; i++){
        string b; cin >> b;
        for(int j = 0 ; j < C ; j++){
            board[i][j] = (b[j] == 'x') ? 1 : 0;
        }
    }
    int N; cin >> N;
    int dir = 0;
    while(true){
        //set cluster
        int cluster_cnt = 0;
        int clusters[100][100];
        vector<vector<int>> cluster_bottom;
        memset(clusters, 0, sizeof(clusters));

        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(board[i][j] == 1 && clusters[i][j] == 0){
                    cluster_cnt += 1;
                    clusters[i][j] = cluster_cnt;
                    vector<int> bottom(C, -1);
                    queue<pi> q;
                    q.push(pi(i,j));
                    bottom[j] = i;
                    while(q.size() > 0){
                        pi _q = q.front(); q.pop();
                        for(int d = 0; d < 4; d++){
                            int ny = _q.first + dy[d]; 
                            int nx = _q.second + dx[d];
                            if(0<= ny && ny<R && 0<=nx && nx<C && clusters[ny][nx] == 0 && board[ny][nx] == 1){
                                if(bottom[nx] == -1){
                                    bottom[nx] = ny;
                                } else {
                                    bottom[nx] = max(ny, bottom[nx]);
                                }
                                clusters[ny][nx] = cluster_cnt;
                                q.push(pi(ny,nx));
                            }
                        }
                    }
                    cluster_bottom.push_back(bottom);
                }
            }
        }
        cout << "clusters : \n";
        for(int i = 0; i < R; i++){
            for(int j = 0 ; j < C ; j++){
                cout << clusters[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        //fall if cluster hasn't ground idx 
        for(int idx = 0 ; idx < cluster_bottom.size() ; idx++){
            vector<int> &cb = cluster_bottom[idx];
            int inAir = 1;
            cout << "cluster " << idx + 1 << " : ";
            for(auto b: cb){
                cout << b << " ";
                if(b == R - 1){
                    inAir = 0;
                    break;
                }
            }
            cout << "\n\n";
            if(inAir){
                int down = 101;
                for(int i = 0 ; i < C; i ++){
                    if(cb[i] != -1){
                        int h;
                        for(h = cb[i] + 1; h < R ; h++){
                            if(board[h][i] == 1){
                                break;
                            }
                        }
                        down = min(h - (cb[i] + 1), down);
                    }
                }
                cout << "down : " << down << "\n";
                for(int i = 0 ; i < R; i++){
                    for(int j = 0 ; j < C; j++){
                        if (clusters[i][j] == idx + 1){
                            board[i][j] -= 1;
                            board[i + down][j] += 1;
                        }
                    }    
                }
                break;
            }
        }
        if(!N--) break;
        //throw, toggle direction
        int r; cin >> r;
        int throw_h = R - r;
        if(dir == 0){
            for(int i = dir; i < C; i++){
                if(board[throw_h][i] == 1){
                    board[throw_h][i] = 0;
                    break;
                }
            }
            dir = C - 1;
        } else {
            for(int i = dir; i >= 0; i--){
                if(board[throw_h][i] == 1){
                    board[throw_h][i] = 0;
                    break;
                }
            }
            dir = 0;
        }
    }
    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C ; j++){
            cout << (board[i][j] == 0 ? '.' : 'x');
        }
        cout <<"\n";
    }
}



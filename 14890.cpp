#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<vector<int>> board(100, vector<int>(100, 0));
int N, L;
int ans = 0;

void init(){
    cin >> N >> L;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
        }
    }
}

void check(){
    for(int i = 0 ; i < N ; i++){
        int canMove = 1;
        int cnt = 1;
        for(int j = 0 ; j < N - 1 ; j++){
            if(board[i][j+1] == board[i][j]){
                cnt += 1;
            } else if(board[i][j+1] == board[i][j] - 1){
                cnt = 1;
                for(int idx = j + 1 ; idx < N - 1; idx++){
                    if(board[i][idx] == board[i][idx+1]){
                        cnt += 1;
                    } else {
                        break;
                    }
                }
                if(cnt >= L){
                    cnt = 0;
                    j += L - 1;
                } else {
                    canMove = 0;
                    break;
                }
            } else if(board[i][j+1] == board[i][j] + 1){
                if(cnt >= L){
                    cnt = 1;
                } else {
                    canMove = 0;
                    break;
                }
            } else {
                canMove = 0;
                break;
            }
        }
        //if(canMove) ans += 1;
        if(canMove) {
            cout << i << "\n";
            ans += 1;
        }
    }
}

void solve(){
    check();
    vector<vector<int>> nboard(100, vector<int>(100,0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            nboard[i][j] = board[j][i];
        }
    }
    board = nboard;
    check();
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
#include<bits/stdc++.h>
using namespace std;

int board[500][500];
int n;

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i + 1 ; j++){
            cin >> board[i][j];
            int sum = board[i][j];
            int ny = i - 1, nx1 = j - 1, nx2 = j;
            if(0 <= ny && ny < n && 0 <= nx1){
                sum = board[i][j] + board[ny][nx1];
            }
            if(0 <= ny && ny < n && nx2 < n){
                sum = max(sum, board[i][j] + board[ny][nx2]);
            }
            board[i][j] = sum;
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++) if(ans < board[n-1][i]) ans = board[n-1][i];
    cout << ans << "\n";
}
#include <bits/stdc++.h>
using namespace std; 

char board[3076][6144];
int N;

void printStar(int n, int h, int bl){
    int m = bl / 2;
    if(h == 3){
        board[0][m] = '*';
        board[1][m-1] = '*';
        board[1][m+1] = '*';
        for(int i = m-2 ; i < m+3 ; i++){
            board[2][i] = '*';
        }
    } else {
        for(int i = h - h / 2; i < h ; i++){
            for(int j = 0 ; j < m ; j++){
                board[i][j] = board[i- h/2][j+ h/2];
            }
        }
        for(int i = h - h / 2; i < h ; i++){
            for(int j = m + 1 ; j < bl ; j++){
                board[i][j] = board[i- h/2][j- h/2];
            }
        }
    }

    if(h == n){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < bl ; j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    } else {
        printStar(n, h * 2, bl);
    }
}

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < 3076 ; i++){
        for(int j = 0 ; j < 6144 ; j++){
            board[i][j] = ' ';
        }
    }
}

void solve(){
    int height = 3; // 3, 6, 12, 24
    int bottomlength = (N / 3 * 5) + (N / 3) - 1;
    printStar(N, height, bottomlength);
}

int main(){
    init();
    solve();
}
#include <bits/stdc++.h>
using namespace std;

int board[15][15];
int N;
int cnt = 0;

bool check(int y, int x){
    //못 놓을 때 true

    int ny, nx1, nx2;
    for(int i = 1 ; i <= y ; i++){
        ny = y - i;
        nx1 = x - i;
        nx2 = x + i;
        if(board[ny][x] == 1) return true;
        if(0<=nx1 && nx1<N){
            if(board[ny][nx1] == 1) return true;
        }
        if(0<=nx2 && nx2<N){
            if(board[ny][nx2] == 1) return true;
        }
    }

    return false;
}

void DFS(int y, int x){
    board[y][x] == 1;
    if(check(y, x)){
        //board[y][x] = 0;
        return;
    }

    if(y == N - 1){
        cnt += 1;
        return;
    }

    for(int i = 0 ; i < N ; i++){
        board[y+1][i] = 1;
        DFS(y+1, i);
        board[y+1][i] = 0;
    }
}

int main(){

    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        memset(board, 0, sizeof(board));
        board[0][i] = 1;
        DFS(0, i);
    }
    cout << cnt << "\n";
}
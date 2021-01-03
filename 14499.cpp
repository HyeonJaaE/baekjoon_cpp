#include<bits/stdc++.h>
using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int board[20][20];
int N, M, r, c, K;
int dice[7];
/*
1번-상단
  2
4 1 3
  5
  6
*/
void roll(int op, int nr, int nc){
    if(op == 1){
        //right
        int tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = tmp;
    } else if(op == 2){
        //left
        int tmp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = tmp;
    } else if(op == 3){
        //up
        int tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = tmp;
    } else if(op == 4){
        //down
        int tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = tmp;
    }
    //복사
    if(board[nr][nc] == 0){
        board[nr][nc] = dice[6];
    } else {
        dice[6] = board[nr][nc];
        board[nr][nc] = 0;
    }
    cout << dice[1] << "\n";
}

void move(int op){
    //이동 여부 판단
    int nr = r + dr[op - 1], nc = c + dc[op - 1];
    if(0 <= nr && nr < N && 0 <= nc && nc < M){
        roll(op, nr, nc);
        r = nr, c = nc;
    }
}

int main(){
    memset(dice, 0, sizeof(dice));
    cin >> N >> M >> r >> c >> K;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0 ; i < K ; i++){
        //1-동, 2-서, 3-북, 4-남
        int op; cin >> op;
        move(op);
    }
}
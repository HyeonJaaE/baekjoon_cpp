#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int board[9][9];
vector<pi> zero;
int out = 0;

bool notVaild(int y, int x){
    int check[10];
    memset(check, 0, sizeof(check));
    for(int i = 0 ; i < 9 ; i++){
        if(check[board[y][i]] == 1 && board[y][i] != 0){
            return true;
        } else {
            check[board[y][i]] += 1;
        }
    }

    memset(check,  0, sizeof(check));
    for(int i = 0 ; i < 9 ; i++){
        if(check[board[i][x]] == 1 && board[i][x] != 0){
            return true;
        } else {
            check[board[i][x]] += 1;
        }
    }

    memset(check,  0, sizeof(check));
    int ny = floor( y / 3 ) * 3;
    int nx = floor( x / 3 ) * 3;
    for(int i = ny ; i < ny + 3 ; i++){
        for(int j = nx ; j < nx + 3 ; j++){
            if(check[board[i][j]] == 1 && board[i][j] != 0){
                return true;
            } else {
                check[board[i][j]] += 1;
            }
        }
    } 
    return false;
}

void DFS(int node, int fill){
    if(out) return;

    if(node == zero.size()){
        cout << "\n";
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        out = 1;
        return;
    }
    
    int y = zero[node].first, x = zero[node].second;
    board[y][x] = fill;

    if(notVaild(y, x)){
        board[y][x] = 0;
        return;
    } else {
        for(int i = 1 ; i <= 9 ; i++){
            DFS(node + 1, i);
        }
    }
    board[y][x] = 0;
}

int main(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) zero.push_back(pi(i,j));
        }
    }
    for(int i = 1 ; i <= 9 ; i++){
        DFS(0, i);
    }

}
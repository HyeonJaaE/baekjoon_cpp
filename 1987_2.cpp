#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = -1;
vector<string> board(20);
int R, C;

void DFS(int y, int x, bitset<26> check){
    bitset<26> bit(board[y][x] - 65);
    if(check == bit){
        return;
    } else {
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0 ; i < 26 ; i++){
        cout << bitset<26>(i) << "\n";
    }
    return 0;
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        cin >> board[i];
    }
    DFS(0, 0, 0);
}
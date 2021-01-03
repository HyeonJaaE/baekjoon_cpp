#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = -1;
vector<string> board(20);
int R, C;

void DFS(int y, int x, int check){

    int bit = (1 << board[y][x] - 65);
    if((check & bit) == bit){
        ans = max(ans, static_cast<int>(bitset<26>(check).count()));
        return;
    } else {
        check |= bit;
    }

    for(int d = 0 ; d < 4 ; d++){
        int ny = y + dy[d], nx = x + dx[d];
        if( 0 <= ny && ny < R && 0 <= nx && nx < C ){
            DFS(ny, nx, check);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        cin >> board[i];
    }
    DFS(0, 0, 0);
    cout << ans;
}
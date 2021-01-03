#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int ans = 11;
int n, m;
pi R, B, O;
vector<string> board(10);

void DFS(int root, vector<string> b, vector<pi> l, int depth){
    if(depth == 11){
        return;
    }

    pi R = l[0], B = l[1];
    pi nR = R, nB = B;

    if(root == 1){
        while(true){
            nR.first -= 1;
            if(b[nR.first][nR.second] == 'O'){
                break;
            } 
            if(b[nR.first][nR.second] == '#'){
                nR.first += 1;
                break;
            } 
        }
        while(true){
            nB.first -= 1;
            if(b[nB.first][nB.second] == 'O'){
                break;
            } 
            if(b[nB.first][nB.second] == '#'){
                nB.first += 1;
                break;
            }
        }

        //파랑 탈출하면 무조건 실패
        if(nB == O){
            return;    
        } else if(nR == O){
            ans = min(ans, depth);
            return;
        }
        
        if(nR == nB){
            if(R.first < B.first) nB.first += 1;
            else nR.first += 1;    
        }

    } else if ( root == 2 ){
        while(true){
            nR.second += 1;
            if(b[nR.first][nR.second] == 'O'){
                break;
            } 
            if(b[nR.first][nR.second] == '#'){
                nR.second -= 1;
                break;
            } 
        }
        while(true){
            nB.second += 1;
            if(b[nB.first][nB.second] == 'O'){
                break;
            } 
            if(b[nB.first][nB.second] == '#'){
                nB.second -= 1;
                break;
            }
        }

        if(nB == O){
            return;    
        } else if(nR == O){
            ans = min(ans, depth);
            return;
        }
        
        if(nR == nB){
            if(R.second < B.second) nR.second -= 1;
            else nB.second -= 1;    
        }
    } else if ( root == 3 ){
        while(true){
            nR.first += 1;
            if(b[nR.first][nR.second] == 'O'){
                break;
            } 
            if(b[nR.first][nR.second] == '#'){
                nR.first -= 1;
                break;
            } 
        }
        while(true){
            nB.first += 1;
            if(b[nB.first][nB.second] == 'O'){
                break;
            } 
            if(b[nB.first][nB.second] == '#'){
                nB.first -= 1;
                break;
            }
        }

        if(nB == O){
            return;    
        } else if(nR == O){
            ans = min(ans, depth);
            return;
        }
        
        if(nR == nB){
            if(R.first < B.first) nR.first -= 1;
            else nB.first -= 1;    
        }
    } else {
        while(true){
            nR.second -= 1;
            if(b[nR.first][nR.second] == 'O'){
                break;
            } 
            if(b[nR.first][nR.second] == '#'){
                nR.second += 1;
                break;
            } 
        }
        while(true){
            nB.second -= 1;
            if(b[nB.first][nB.second] == 'O'){
                break;
            } 
            if(b[nB.first][nB.second] == '#'){
                nB.second += 1;
                break;
            }
        }

        if(nB == O){
            return;    
        } else if(nR == O){
            ans = min(ans, depth);
            return;
        }
        
        if(nR == nB){
            if(R.second < B.second) nB.second += 1;
            else nR.second += 1;    
        }
    }

    if(root == 1 || root == 3){
        DFS(2, b, {nR, nB}, depth + 1);
        DFS(4, b, {nR, nB}, depth + 1);    
    } else {
        DFS(1, b, {nR, nB}, depth + 1);    
        DFS(3, b, {nR, nB}, depth + 1);    
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> board[i];
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == 'R'){
                R = pi(i, j);
            }
            if(board[i][j] == 'B'){
                B = pi(i, j);
            }
            if(board[i][j] == 'O'){
                O = pi(i, j);
            }
        }
    }
    for(int i = 1 ; i <= 4 ; i++){
        vector<pi> loc = {R, B};
        DFS(i, board, loc, 1);
    }    

    if(ans == 11){
        cout << -1 << "\n";
    } else {
        cout << ans <<"\n";
    }
}
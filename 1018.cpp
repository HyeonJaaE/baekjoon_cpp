#include<bits/stdc++.h>
using namespace std;

string colors[2] = {"BWBWBWBWBW", "WBWBWBWBWB"};
vector<string> board[2];
vector<string> v;
int N, M;
int ans = 987654321;

int check(int boardn, int r, int c){
    int cnt = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board[boardn][i][j] != v[i + r][j + c]) cnt += 1;
        }
    }
    return cnt;
}

int main(){
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            board[i].push_back(colors[(j + i) % 2]);
        }
    }

    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        string s; cin >> s;
        v.push_back(s);
    }

    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j + 8 <= N ; j++){
            for(int k = 0 ; k + 8 <= M ; k++){
                ans = min(ans, check(i, j, k));
            }
        }
    }

    cout << ans << "\n";

}
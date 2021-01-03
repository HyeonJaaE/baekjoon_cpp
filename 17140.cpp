#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAX = 100;
int r, c, k;
int h = 3, w = 3;
vector<vector<int>> board(3, vector<int>(3, 0));

bool comp(pi a, pi b){
    if(a.second == b.second){
        return a.first < b.first;
    } else{
        return a.second < b.second;
    }
}

int solve(int time){
    int ans;
    while(time--){
        if(h >= w){
            for(int i = 0 ; i < h ; i++){
                vector<pi> cnt(100);
                for(auto n: board[i]){
                    cnt[n].first = n;
                    cnt[n].second += 1;
                }
                sort(cnt.begin(), cnt.end(), comp);
            }
            
        } else {
            continue;
            for(int i = 0 ; i < w ; i++){
                cout << 1;
            }
        }

        if(board[r][c] == k){
            return ans;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r >> c >> k;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> board[i][j];
        }
    }
    cout << solve(100) << "\n";
}

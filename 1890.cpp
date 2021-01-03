#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

const int MAXN = 100;
vector<vector<int>> board;
vector<vector<ll>> cnt(MAXN, vector<ll>(MAXN, 0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    int N; cin >> N;
    
    for(int i = 0;  i < N ; i++){
        vector<int> v;
        for(int j = 0 ; j < N ; j++){
            int num; cin >> num;
            v.push_back(num);
        }
        board.push_back(v);
    }
    
    cnt[0][0] = 1;
    for(int i = 0 ; i < N; i++){
        for(int j =0 ; j < N; j++){
            int dist = board[i][j];
            if(dist == 0) continue;
            if(i+dist<N) cnt[i+dist][j] += cnt[i][j];
            if(j+dist<N) cnt[i][j+dist] += cnt[i][j];
        }
    }
    cout << cnt[N-1][N-1];
}
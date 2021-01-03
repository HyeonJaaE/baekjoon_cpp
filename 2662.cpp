#include <bits/stdc++.h>
using namespace std;

int benefit[20][300];
int dp[21][300];
int corp[21][300];

int main(){
    int N, M; cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        int cost; cin >> cost;
        for(int j = 0 ; j < M ; j++){
            cin >> benefit[cost][j];
        }
    }
    
    for(int i = 1 ; i <= M; i++){
        // A, B, C, ...
        for(int c = 1 ; c <= N ; c ++){
            // A1, A2, A3, ...
            for(int k = c ; k <= N ; k++){
                pair<int, int> maxv = max({pair(dp[i],), pair(,), pair()})
            }
        }
    }
    for(int i = 0 ; i < 10; i++){
        cout << corp[i] << " ";
    }
    cout << "\n";
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10 ; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
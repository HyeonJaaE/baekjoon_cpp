#include<bits/stdc++.h>
using namespace std;

int dp[101][10];
int N;
int ans = 0;

int main(){
    cin >> N;
    for(int i = 1 ; i <= 9 ; i++){
        dp[1][i] = 1;
    }
    for(int i = 2 ; i <= 100 ; i++){
        for(int j = 0 ; j <= 9 ; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][1];
            } else if(j == 9){
                dp[i][j] = dp[i-1][8];
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
        }
    }
    for(int i = 0 ; i <= 9 ; i++){
        ans += dp[N][i];
        ans %= 1000000000;
    }
    cout << ans << "\n";
    //dp[i][j] => i번째 자리가 j 일 때 값
    //i 번째 자리가 0 이 되려면 i - 1번째 자리가 1
    //i 번째 자리가 1 이 되려면 i - 1번째 자리가 0 이나 2

    
}
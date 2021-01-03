#include<bits/stdc++.h>
using namespace std;

int dp[1000];
int price[1000];
int N;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> price[i];
    for(int i = 1 ; i <= N ; i++){
        for(int j = i ; j <= N ; j++){
            dp[j] = max(dp[j], dp[j-i] + price[i-1]);
        } 
    }
    cout << dp[N] << "\n";
}

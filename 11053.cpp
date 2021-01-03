#include <bits/stdc++.h>
using namespace std; 

int dp[1001];
int arr[1001];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i];
    }

    

    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }   
        ans = max(dp[i], ans);
    }

    cout << ans << "\n";
}
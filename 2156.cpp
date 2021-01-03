#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    int N; cin >> N;
    vector<int> wines;
    vector<int> dp;
    cout << "g";
    wines.push_back(0);
    while(N--){
        int wine; cin >> wine;
        wines.push_back(wine);
    }
    cout << "g";
    dp[0] = wines[0];
    cout << "g";
    dp[1] = wines[1];
    cout << "g";
    dp[2] = wines[2] + dp[1];


}


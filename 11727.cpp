#include<bits/stdc++.h>
using namespace std;

int N;
int DP[1001];

int main(){
    cin >> N;
    DP[1] = 1;
    DP[2] = 3;
    for(int i = 3 ; i < 1001 ; i++){
        DP[i] = DP[i-2] * 2 + DP[i-1];
        DP[i] %= 10007;
    }
    cout << DP[N] << "\n";
    return 0;
}
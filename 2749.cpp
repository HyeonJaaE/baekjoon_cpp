#include<bits/stdc++.h>
using namespace std;

int N; // 1 ~ 1,000,000,000,000,000,000
int ans = 0;
int fib[2] = {0, 1};
int cnt[2];

int getFib(int n){
    if(n == 0 || n == 1){
        cnt[n] += 1;
        return n;
    }
    
    return getFib(n-2) + getFib(n-1);
}

void init(){
    //cin >> N;
}

void solve(){
    int cnt = 0;
    for(int i = 0 ; i < 1000000000000000000 ; i++){
        cnt += 1;
        cnt % 1000000;
    }
    cout << cnt << "\n";
    //cout << ans % 1000000 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
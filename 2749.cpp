#include<bits/stdc++.h>
using namespace std;

long long N; // 1 ~ 1,000,000,000,000,000,000
const int mod = 1000000;
const int period = mod / 10 * 15;
int fib[period];

void init(){
    cin >> N;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i < period ; i++){
        fib[i] = fib[i-2] + fib[i-1];
        fib[i] %= mod;
    }
}

void solve(){
    cout << fib[N % period];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
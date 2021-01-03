#include <bits/stdc++.h>
using namespace std; 

int n;
long long fib[91];

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i <= 90 ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin >> n;
}

void solve(){
    cout << fib[n] << "\n";
}

int main(){
    init();
    solve();
}
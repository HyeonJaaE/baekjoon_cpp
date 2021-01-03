#include<bits/stdc++.h>
using namespace std;

int prime[10001];
int M, N;
int ans1 = 0;
int ans2 = 0;

void init(){
    cin >> M >> N;
    memset(prime, 0, sizeof(prime));
    prime[1] = 0;
    for(int i = 2 ; i < 10001; i++){
        if(prime[i] == 0) prime[i] = 1;
        for(int j = 2 ; i * j < 10001 ; j++){
            prime[i*j] = -1;
        }
    }
}

void solve(){
    for(int i = M ; i <= N ; i++){
        if(prime[i] == 1){
            ans1 += i;
            if(ans2 == 0) ans2 = i;
        }
    }
    if(ans1 == 0) cout << -1 << "\n";
    else cout << ans1 << "\n" << ans2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
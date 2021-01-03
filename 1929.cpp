#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1000001;
int prime[MAXN];
int M, N;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    memset(prime, 0, sizeof(prime));
    //1 일때 소수
    prime[1] = -1;
    for(int i = 2 ; i < MAXN ; i++){
        if(prime[i] == 0){
            prime[i] = 1;
        }
        for(int j = 2 ; i * j < MAXN ; j++){
            prime[i * j] = -1;
        }
    }
}

void solve(){  
    for(int i = N ; i <= M ; i++){
        if(prime[i] == 1) cout << i << "\n";
    }
}

int main(){
    init();
    solve();
}
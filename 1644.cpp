#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

const int MAXN = 4000001;
vector<int> prime;
int check[MAXN];
int sumcnt[MAXN];
int N;

int ans = 0;

void init(){
    cin >> N;
    memset(check, 0, sizeof(check));
    for(int i = 2 ; i <= N ; i++){
        if(!check[i]) check[i] = 1;
        for(int j = 2 ; i * j <= N ; j++)
            check[i*j] = -1;
    }

    for(int i = 1 ; i <= N ; i++)
        if(check[i] == 1) prime.push_back(i);   
}    


void solve(){
    int l = 0, r = 0;
    int sum = 0;
    while(true){
        if(r == prime.size() && sum < N) break;

        if(sum >= N){
            sum -= prime[l++];
        } else {
            sum += prime[r++];
        } 

        if(sum == N){
            ans += 1;
        }
        
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
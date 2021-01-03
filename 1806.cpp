#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAXN = 100001;
int nums[MAXN];
int sums[MAXN];
int N, S;
int ans = INF;

void init(){
    cin >> N >> S;
    for(int i = 1 ; i <= N ; i++){
        cin >> nums[i];
        sums[i] = sums[i-1] + nums[i];
    }
}

void solve(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = i - 1; j >= 0 ; j--){
            int tmp = sums[i] - sums[j];
            if(tmp >= S){
                ans = min(ans, i - j);
                break;
            } 
        }
    }

    if(ans == INF){
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
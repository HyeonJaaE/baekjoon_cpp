#include <bits/stdc++.h>
using namespace std; 

int ans[1001];
int N;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
}

void solve(){
    for(int i = 1 ; i <= 1000 ; i++){
        string s = to_string(i);
        //3자리 수 부터 하나
        int valid = 1;
        if(s.length() >= 3){
            for(int j = 1 ; j < s.length() - 1 ; j++){
                if(s[j-1] - s[j] != s[j] - s[j+1]){
                    valid = 0;
                    break;
                }
            }
        } 
        if(valid){
            ans[i] += ans[i-1] + 1;
        } else {
            ans[i] = ans[i-1];
        }
    }
    cout << ans[N] << "\n";
}

int main(){
    init();
    solve();
}
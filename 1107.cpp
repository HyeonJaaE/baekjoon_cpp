#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int button[10];
int N, M;
int cur = 100;
int ans = 987654321;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    memset(button, 0, sizeof(button));
    while(M--){
        //1 - broken
        int brokenbtn; cin >> brokenbtn;
        button[brokenbtn] = 1;
    }
}

void solve(){
    if(N == cur){
        cout << 0 << "\n";
        return;
    } else{
        ans = min(ans, abs(N - cur));
    }
    

    for(int i = N ; i >= 0 ; i--){
        string s = to_string(i);
        int isValid = 1;
        for(int j = 0 ; j < s.length() ; j++){
            if(button[s[j] - 48] == 1){
                isValid = 0;
                break;
            }
        }
        if(isValid){
            ans = min(ans, (int)(s.length() + N - i));
            break;
        }
    }

    for(int i = N ; i <= 987654321 ; i++){
        string s = to_string(i);
        if((int)(s.length() + i - N) > ans) break;
        int isValid = 1;
        for(int j = 0 ; j < s.length() ; j++){
            if(button[s[j] - 48] == 1){
                isValid = 0;
                break;
            }
        }
        if(isValid){
            ans = min(ans, (int)(s.length() + i - N));
            break;
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    init();
    solve();
}
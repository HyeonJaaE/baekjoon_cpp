#include<bits/stdc++.h>
using namespace std;

int N;
int ans = 0;

bool isValid(string s){
    int check[26];
    memset(check, 0, sizeof(check));
    check[s[0] - 97] += 1;
    if(s.length() > 1){
        for(int i = 1 ; i < s.length() ; i++){
            if(check[s[i] - 97] != 0 && s[i-1] != s[i]){
                return false;
            } else {
                check[s[i] - 97] += 1;
            }
        }
    }
    return true;
}

int main(){
    cin >> N;
    while(N--){
        string s; cin >> s;
        if(isValid(s)) ans += 1;
    }
    cout << ans << "\n";
    return 0;
}
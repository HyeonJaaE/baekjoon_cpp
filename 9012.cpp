#include<bits/stdc++.h>
using namespace std;

int T;

string solve(){
    int cnt = 0;
    string s; cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '(') cnt += 1;
        else if(s[i] == ')') cnt -= 1;
        if(cnt < 0) return "NO";
    }
    if(cnt != 0) return "NO";
    return "YES";
}

int main(){
    cin >> T;
    while(T--){
        cout << solve() << "\n";
    }
}
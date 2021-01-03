#include <bits/stdc++.h>

using namespace std; 

vector<string> li;

int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int N; cin >> N;
        string s; cin >> s;
        
        int cnt = 1;
        for(int i = 0 ; i < s.length(); i++){
            cnt += 1;
            if(s[i] == 'L') i += 1;
        }

        cout << min(N, cnt);
}
#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int i, j; cin >> i >> j;
        vector<string> belt;
        int _i = i;
        while(_i--){
            string s; cin >> s;
            belt.push_back(s);
        }
        
        int cnt = 0;
        for(int c = 0; c < j - 1; c++) if(belt[i-1][c] == 'D') cnt +=1;
        for(int r = 0; r < i - 1; r++) if(belt[r][j-1] == 'R') cnt +=1;
        cout << cnt << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    int N; cin >> N;
    
    vector<string> v;
    for(int i = 0 ; i < N; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    
    pi ans(0, 0);
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(v[i][j] == '.'){
                cnt += 1;
            } else {
                if(cnt >= 2) ans.first += 1;
                cnt = 0;
            }
        }
        if(cnt >= 2) ans.first += 1;
    }

    for(int j = 0; j < N; j++){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(v[i][j] == '.'){
                cnt += 1;
            } else {
                if(cnt >= 2) ans.second += 1;
                cnt = 0;
            }
        }
        if(cnt >= 2) ans.second += 1;
    }

    cout << ans.first << " " << ans.second << "\n";
}


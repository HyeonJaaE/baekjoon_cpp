#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(true){
        string game; cin >> game;
        if(game == "end"){
            break;
        } else {
            int cnt = 0;
            for(int i = 0 ; i < 3 ; i++){
                int idx = i*3;
                if(game[idx] == game[idx+1] && game[idx] == game[idx+2]){
                    cnt += 1;
                }
            }
            if(cnt > 1){
                cout << "invalid\n";
            }
        }
    }
}
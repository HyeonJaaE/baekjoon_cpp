#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int cnt = 0;
    int i = 665;
    while(i++){
        string s = to_string(i);
        if(s.find("666") != -1){
            cnt += 1;
        };
        if(cnt == N){
            cout << s << "\n";
            break;
        }
    }
}
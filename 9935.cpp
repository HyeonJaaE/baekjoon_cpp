#include <bits/stdc++.h>
using namespace std; 

string str, bomb;

void init(){
    cin >> str >> bomb;
}

void solve(){
    while(str.find(bomb, 0) != string::npos){
        vector<string> split;
        size_t cur, prev = 0;
        string nstr;
        while((cur = str.find(bomb, prev)) != string::npos){
            nstr += str.substr(prev, cur - prev);
            prev = cur + bomb.length();
        }
        nstr += str.substr(prev, cur - prev);
        str = nstr;
    }

    if(str == ""){
        cout << "FRULA\n";
    } else {
        cout << str << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    
    string str;
    getline(cin, str);
    int cnt = 1;
    for(auto s: str){
        if( s == ' ' ) cnt += 1;
    }
    
    if(str[0] == ' ') cnt -= 1;
    if(str[str.length() - 1] == ' ') cnt -= 1;
    cout << cnt << "\n";
}


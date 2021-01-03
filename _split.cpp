#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   

    string str = "hello world";
    vector<string> v;
    getline(cin, str);
    size_t loc, prev = 0;
    while( (loc = str.find(' ', prev)) != string::npos ){
        v.push_back(str.substr(prev, loc - prev));
        prev = loc + 1;
    }
    v.push_back(str.substr(prev, loc - prev));
}


        
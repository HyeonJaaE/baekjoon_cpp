#include <bits/stdc++.h>

using namespace std;
using p = pair<int, int>;

bool cmp(p& a, p& b){
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    
    string str;
    getline(cin, str);
    
    vector<p> v(100);

    for(auto s: str){
        int idx = toupper(s);
        if(v[idx].first == 0) v[idx].first = idx;
        v[idx].second += 1;
    }
    
    sort(v.begin(), v.end(), cmp);

    char ans = ( v[0].second == v[1].second ) ? '?' : v[0].first;
    cout << ans << "\n";
}


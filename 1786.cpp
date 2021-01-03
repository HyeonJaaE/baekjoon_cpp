#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<int> get_failure(string p){
    int len = p.length();
    int j = 0;
    vector<int> r(len, 0);
    for(int i = 1 ; i < len; i++){
        while( j > 0 && p[i] != p[j]){
            j = r[j - 1];
        }
        if(p[i] == p[j]){
            r[i] = ++j;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string T, P;
    int bar = 100;
    getline(cin, T);
    getline(cin, P);
    vector<int> f = get_failure(P);
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < T.length(); i++){
        while (j > 0 && T[i] != P[j])     
            j = f[j - 1];     
        if (T[i] == P[j]){         
            if (j == P.length() - 1){ 
                ans.push_back(i - P.length() + 1);
                j = f[j]; 
            }
            else
                j++; 
        }
    }
    cout << ans.size() << "\n";
    for(auto foo: ans) cout << foo + 1 << " ";
    cout << "\n";

    //cout << "T : " << T << "\n";
    //cout << "P : " << P << "\n";
    //for(auto foo: f) cout << foo << " ";
    //cout << "\n";
    
}
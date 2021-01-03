#include <bits/stdc++.h>
using namespace std;

string checklist[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
string s;

int main(){
    cin >> s;
    int len = s.length();
    for(auto cl: checklist){
        while(s.find(cl) != string::npos){
            len -= cl.length() - 1;
            size_t loc = s.find(cl);
            s.erase(s.begin() + loc, s.begin() + loc + cl.length());
            s.insert(s.begin() + loc, '*');
        }
    }
    cout << len << "\n";
    return 0;
}
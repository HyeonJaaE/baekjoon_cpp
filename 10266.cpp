#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n; cin >> n;
    vector<int> c1(n), c2(n);
    for(int i = 0 ; i < n ; i++) cin >> c1[i];
    for(int i = 0 ; i < n ; i++) cin >> c2[i];
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    c1.push_back(c1.front() + 360000);
    c2.push_back(c2.front() + 360000);
    int diff = -1;
    for(int i = 0 ; i < n ; i++){
        if(diff == -1) diff = abs(abs(c1[i] - c1[i+1]) - abs(c2[i] - c2[i+1]));
        else if(abs(abs(c1[i] - c1[i+1]) - abs(c2[i] - c2[i+1])) != diff){
            cout << "impossible\n";
            return 0;
        }
    }
    cout << "possible\n";
    
}
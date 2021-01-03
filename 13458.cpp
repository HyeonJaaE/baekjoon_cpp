#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;
using ll = long long;

int n, b, c;
vector<int> students;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int student; cin >> student;
        students.push_back(student);
    }    
    cin >> b >> c;
    ll cnt = 0;
    for(auto s: students){
        cnt += 1;
        if( s <= b ) continue;
        else{
            s -= b;
            cnt += s / c;
            if(s % c != 0) cnt += 1;
        }
    }
    cout << cnt << "\n";

}
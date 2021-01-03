#include <bits/stdc++.h>
using namespace std; 

vector<char> ans;
queue<int> v;
stack<int> s;
int N;

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int n; cin >> n;
        v.push(n);
    }
}

void solve(){
    int i = 1;
    while(true){
        if(!s.empty() && v.front() == s.top()){
            ans.push_back('-');
            s.pop();
            v.pop();
        } else {
            ans.push_back('+');
            s.push(i++);
        }

        if(v.empty()) break;
        if(!s.empty() && s.top() > N ) break;
    }

    if(v.empty()){
        for(auto a: ans) cout << a << "\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}
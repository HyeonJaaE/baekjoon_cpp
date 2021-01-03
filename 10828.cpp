#include <bits/stdc++.h>
using namespace std; 

stack<int> q;
int N;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;    
}

void solve(){
    while(N--){
        string op1;
        cin >> op1;
        if(op1 == "push"){
            int op2; cin >> op2;
            q.push(op2);
        } else if(op1 == "pop"){
            if(q.empty()) cout << -1 << "\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            } 
        } else if(op1 == "top"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.top() << "\n";
        } else if(op1 == "empty"){
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else {
            //size
            cout << q.size() << "\n";
        }
    }
}

int main(){
    init();
    solve();
}
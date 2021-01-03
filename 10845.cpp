#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int N;

int main(){
    cin >> N;
    string op;   
    while(N--){
        cin >> op;
        if(op == "push"){
            int n; cin >> n;
            q.push(n);
        }
        if(op == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if(op == "size"){
            cout << q.size() << "\n";
        }
        if(op == "empty"){
            cout << (q.empty() ? 1 : 0) << "\n";
        }
        if(op == "front"){
            if(q.empty()){
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        }
        if(op == "back"){
            if(q.empty()){
                cout << -1 <<"\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
}
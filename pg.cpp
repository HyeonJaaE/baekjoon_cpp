#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

void solve(string str){    
    stack<char> op;
    for(auto s: str){
        if(isalpha(s)){
            cout << s;
        } else if (s == '*' || s == '/'){
            if(!op.empty() && (op.top() == '*' || op.top() == '/')){
                cout << op.top();
                op.pop();
            }
            op.push(s);
        } else if (s == '+' || s == '-'){
            if(!op.empty() && op.top() != '(' ){
                cout << op.top();
                op.pop();
            }
            op.push(s);
        } else if (s == ')'){
            while(!op.empty()){
                char tmp = op.top();
                op.pop();
                if(tmp == '(') break;
                else cout << tmp;
            }
        } else {
            op.push(s);
        }
    }

    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
    cout << "\n";   
}

void solve2(string str){
        stack<char> op;
    for(auto s: str){
        if(isalpha(s)){
            cout << s;
        } else if (s == '*' || s == '/'){
            if(!op.empty() && (op.top() == '*' || op.top() == '/')){
                cout << op.top();
                op.pop();
            }
            op.push(s);
        } else if (s == '+' || s == '-'){
            while(!op.empty() && op.top() != '(' ){
                cout << op.top();
                op.pop();
            }
            op.push(s);
        } else if (s == ')'){
            while(!op.empty()){
                char tmp = op.top();
                op.pop();
                if(tmp == '(') break;
                else cout << tmp;
            }
        } else {
            op.push(s);
        }
    }

    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
    cout << "\n";
}

int main(){
    while(true){
        string s; cin >> s;
        solve(s);
        solve2(s);
    }
}   

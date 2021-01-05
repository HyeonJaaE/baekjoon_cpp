#include<bits/stdc++.h>
using namespace std;

string str, ans;
stack<char> op;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
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
    
    return 0;
}
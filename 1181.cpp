#include<bits/stdc++.h>
using namespace std;

vector<string> li;
int N;

bool comp(string a, string b){
    if(a.length() < b.length()){
        return true;
    } else if(a.length() == b.length()){
        return a < b;
    } else {
        return false;
    }
}

int main(){
    cin >> N;
    while(N--){
        string s; cin >> s;
        li.push_back(s);
    }    
    cout << "\n";
    sort(li.begin(), li.end(), comp);
    for(int i = 0 ; i < li.size(); i++){
        if(i > 0 && li[i-1] == li[i]) continue;
        cout << li[i] << "\n";
    }
}
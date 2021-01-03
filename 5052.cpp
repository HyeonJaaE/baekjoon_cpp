#include<bits/stdc++.h>
using namespace std;

class Trie{
    private:
        Trie *child[10];
        bool finish = false;

    public:
        bool insert(string s);
};

bool Trie::insert(string s){
    Trie *cur = this;
    for(int i = 0 ; i < s.length() ; i++){
        int next = s[i] - 48;
        if(cur->child[next] == NULL){
            cur->child[next] = new Trie();
            cur = cur->child[next];
            if(i == s.length() - 1) cur->finish = true;
        } else {
            if(i == s.length() - 1) return false;
            if(cur->child[next]->finish) return false;
            cur = cur->child[next];
        }
    }
    return true;
}

vector<string> nums;
Trie *trie;
int T, N;

void init(){
    cin >> N;
    trie = new Trie();
}

void solve(){
    bool isValid = true;
    for(int i = 0 ; i < N ; i++){
        string s; cin >> s;
        if(!trie->insert(s)) isValid = false;
    }

    if(isValid){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        init();
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std; 

char mos[5] = {'a', 'e', 'i', 'o', 'u'};
vector<char> v;
int L, C;


void DFS(int root, string text){
    text = text + v[root];

    if(text.length() == L ){
        int mo = 0, ja = 0;
        for(auto t: text){
            if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u'){
                mo += 1;
            } else {
                ja += 1;
            }
        }
        if(mo >= 1 && ja >= 2){
            cout << text << "\n";
        }
    }

    for(int i = root + 1 ; i < C ; i++){
        DFS(i, text);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //L 모음 1, 자음 2 이상
    cin >> L >> C;
    for(int i = 0 ; i < C ; i++){
        char c; cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    /* for(auto foo: v){
        cout << foo << " ";
    }
    cout << "\n"; */
    for(int i = 0 ; i < C ; i++){
        DFS(i, "");
    }
}
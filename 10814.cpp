#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pair<pi, string>> info;
int N;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int age;
        string name;
        cin >> age >> name;
        info.push_back(make_pair(pi(age, i), name));
    }
    sort(info.begin(), info.end());
    for(auto i: info) cout << i.first.first << " " << i.second << "\n";
}

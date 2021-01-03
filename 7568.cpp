#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pi> info;
vector<pi> compWeight;
int ans[50];
int N;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int w, h; cin >> w >> h;
        info.push_back(pi(w,h));
    } 
    for(int i = 0 ; i < info.size() ; i++){
        pi cur = pi(0, i);
        for(int j = 0 ; j < info.size() ; j++){
            //나보다 큰 사람 구하기
            if(info[i].first < info[j].first && info[i].second < info[j].second){
                cur.first -= 1;
            }
        }
        compWeight.push_back(cur);
    }
    sort(compWeight.begin(), compWeight.end());
    for(int i = 0 ; i < compWeight.size() ; i++){
        ans[compWeight[i].second] = -(compWeight[i].first - 1);
    }
    for(int i = 0 ; i < N ; i++) cout << ans[i] << " ";
    cout << "\n";
}
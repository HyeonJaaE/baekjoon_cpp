#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
using pl = pair<ll, ll>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pl> candies;
    int n; cin >> n;
    while(n--){
        int A; cin >> A;
        if(A == 1){
            ll B; cin >> B;
            for(int i = 0 ; i < candies.size(); i++){
                B -= candies[i].second;
                if( B <= 0 ){
                    cout << candies[i].first << "\n";
                    candies[i].second -= 1;
                    if(candies[i].second == 0) candies.erase(candies.begin() + i);
                    break;
                }
            }
        } else {
            ll B, C; cin >> B >> C;
            pl candy = make_pair(B,C);
            if( candies.size() == 0) candies.push_back(candy);
            else{
                int l = 0;
                int r = candies.size();
                int mid = 0;
                while(l < r){
                    mid = (l + r) / 2;
                    if(candy.first > candies[mid].first){
                        l = mid + 1;
                        continue;
                    }else if(candy.first <= candies[mid].first){
                        r = mid;
                        continue;
                    }
                }
                if(candies[r].first == candy.first){
                    candies[r].second += candy.second;
                    if(candies[r].second == 0) candies.erase(candies.begin() + r);
                }
                else candies.insert(candies.begin() + r, candy);
            }
        }
        cout << "candies : ";
        for( auto foo: candies){
            cout << "(" << foo.first << "," << foo.second << ") -";
        }
        cout << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int visited[26];
int cnt[26][8];
int N, ans;

int num = 9;

void init(){
    memset(visited, -1, sizeof(visited));
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for(int j = 0 ; j < s.length() ; j++){
            visited[s[j] - 65] = 0;
            cnt[s[j] - 65][j] += 1;
        }
    }
}

void solve(){
    bool out = true;
    while(out){
        out = false;

        pi max_sum = pi(-1, -1);
        for(int i = 0 ; i < 26 ; i++){
            if(visited[i] != 0) continue;
            int sum = 0;
            for(int j = 0 ; j < 8 ; j++){
                sum += cnt[i][j] * pow(10, j) * num;
            }
            max_sum = max(pi(sum, i), max_sum);
        }

        ans += max_sum.first;
        visited[max_sum.second] = 1;
        num -= 1;
        for(int i = 0 ; i < 26 ; i++){
            if(visited[i] == 0){
                out = true;
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
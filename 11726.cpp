#include<bits/stdc++.h>
using namespace std;

int cnt[1001];
int n;

int main(){
    cin >> n;
    cnt[1] = 1;
    cnt[2] = 2;
    for(int i = 3 ; i <= 1000 ; i++){
        cnt[i] = cnt[i-2] + cnt[i-1];
        cnt[i] %= 10007;
    }
    cout << cnt[n] << "\n";
}
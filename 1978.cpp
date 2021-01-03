#include<bits/stdc++.h>
using namespace std;

int N;
int ans = 0;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int isPrime = 1;
        int n; cin >> n;
        if(n == 2){
            ans += 1;
        } else if(n > 2){
            for(int j = 2 ; j < n ; j++){
                if(n % j == 0){
                    //not prime
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime) ans += 1;
        }
    }
    cout << ans << "\n";
}
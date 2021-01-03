#include<bits/stdc++.h>
using namespace std;

long long tri[101] = {-1, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
int T, N;

int main(){
    for(int i = 10 ; i < 100 ; i++){
        tri[i+1] = tri[i] + tri[i-4];
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << tri[N] << "\n";
    }    
}
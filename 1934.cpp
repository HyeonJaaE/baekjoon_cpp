#include<bits/stdc++.h>
using namespace std;

int T;


int getgcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int getlcd(int a, int b){
    return a * b / getgcd(max(a,b), min(a,b));
}

int main(){
    cin >> T;
    while(T--){
        int A, B;
        cin >> A >> B;
        cout << getlcd(A, B) << "\n";
    }    
}
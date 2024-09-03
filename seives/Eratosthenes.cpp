#include <bits/stdc++.h>
using namespace std;

void Eratosthenes(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2 ; i*i <= n; i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }    
        }
    }

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;

    Eratosthenes(n);


}
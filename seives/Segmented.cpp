#include <bits/stdc++.h>
using namespace std;


            //  segmented seive
            //  works in the long range numbers left and right
            //  left and right are the range of numbers we want to find primes in
            //  returns a vector of boolean values where left <= i <= right and primes[i] is true

            // main advantage is works in if constrains is more than 10^6

// seives of eratosthenes

vector<int> simpleSeive(int n){
    vector<bool> isPrime(n+1,true);
    vector<int> primes;
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=0;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

    return primes;
}

void segmented(int l,int r){


    // step:1 create an all primes upto sqrt(r);
    // step:2 create an dummy array which is holds the size of r-l+1.because it will dummyfy the range to the aspect ranges.
    // step:3 iterate over the range from l to r and mark the multiples of primes as composite.
    // step:4 return the array which holds the primes in the range [l,r]

    vector<int> primes = simpleSeive(sqrt(r));

    vector<bool> isPrime(r-l+1, true);

    for(int i:primes){
        int firsrMultiply = (l/i) * i;
        if(firsrMultiply < l) firsrMultiply+=i;

        for(int j = max(firsrMultiply, i*i); j<=r; j+=i){
            isPrime[j-l]=false;
        }
        
    }

    for(int i=l;i<=r;i++){
        if(isPrime[i-l]){
            cout<<i<<" ";
        }
    }

}

int main(){
    int L=110,R=130;
    segmented(L,R);
    return 0;

}
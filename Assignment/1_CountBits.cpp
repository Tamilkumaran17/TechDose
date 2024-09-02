#include <bits/stdc++.h>
using namespace std;


int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"The number of bits are in " << n << " is ";
    cout<<countBits(n)<<endl;


    return 0;
}
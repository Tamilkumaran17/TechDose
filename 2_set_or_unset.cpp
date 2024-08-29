#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"Enter the position of the bit to check (0-indexed) : ";
    cin>>i;

    if ((n >> i) & 1)
        cout<<"The bit at position " << i << " is set." << endl;
    else
        cout<<"The bit at position " << i << " is not set." << endl;

    return 0;
}
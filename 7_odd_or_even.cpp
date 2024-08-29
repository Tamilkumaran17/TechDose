#include <bits/stdc++.h>
using namespace std;

void check(int a){
    if(a & 1 == 1) cout<<"Odd";
    else cout<<"Even";
}

int main(){
    int a,b;
    cout<<"Enter A  : ";
    cin>>a;
    check(a);
    
}
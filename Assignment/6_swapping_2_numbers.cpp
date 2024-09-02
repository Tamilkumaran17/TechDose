#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

int main(){
    int a,b;
    cout<<"Enter A and B : ";
    cin>>a>>b;
    swap(a,b);
    cout<<"The swap of A and B : "<< a <<" "<< b;
}
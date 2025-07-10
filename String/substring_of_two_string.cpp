// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";

    
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    string a,b;
    cin>>a>>b;
    
    if(a.size() < b.size())
    {
        cout<<0;
        return 0;
    }
    
    int n=a.size(), m=b.size();
    for(int i=0;i<=n-m; i++)
    {
        int j=0;
        
        while( j<m && a[i+j] == b[j])
        j++;
        
        if(j==m)
        {
            cout<<1;
            return 0;
        }
        
    }
    cout<<0;

    return 0;
}
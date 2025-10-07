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
    
    string s="PROGRAM";
    
    int n=s.size();
    
    int mid = n/2;
    
    int l=0,r=n-1;
    
    vector<vector<char>> ans(n,vector<char>(n,' '));
    
    
        for(int i=0;i<=mid && l <=r;i++)
        {
             
            for(int j=0;j<n;j++)
            {
                if(l==j && r==j)
                {
                    ans[i][j] = s[l];
                }
                else
                {
                    if(l==j) ans[i][j] = s[l];
                    if(r==j) ans[i][j] = s[r];
                }
            }
            
            l++;
            r--;
        }

    
    l=mid-1, r=mid+1;
    
    for(int i=mid+1; i<n && l >=0 && r < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if(l==j)
             ans[i][j] = s[j];
            
            if(r==j)
             ans[i][j] = s[j];
        }
        l--;
        r++;
        
    }
    
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<ans[i][j]<<" ";
        
    }
    cout<<endl;
    }
    
    
    

    return 0;
}
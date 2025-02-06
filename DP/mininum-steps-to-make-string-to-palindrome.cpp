#include <bits/stdc++.h>
using namespace std;

int palin(string &s)
{
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,1));
    
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j])
            dp[i][j]=dp[i+1][j-1]+2;
            else
            dp[i][j]= max(dp[i+1][j], dp[i][j-1]);
        }

    }
    return n-dp[0][n-1];

    //  int n = s.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
        
    //     for (int i = 0; i < n; i++) {
    //         dp[i][i] = 1;
    //     }
        
    //     for (int length = 2; length <= n; length++) { 
    //         for (int i = 0; i <= n - length; i++) {
    //             int j = i + length - 1;  
                
    //             if (s[i] == s[j]) {
    //                 dp[i][j] = dp[i + 1][j - 1] + 2;
    //             } else {
    //                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
        
    //      int lpsLength = dp[0][n - 1];
        
    //      return n - lpsLength;
    
    


}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    
    string s;
    cin>>s;
    // cout<<s;
    cout<<palin(s);
}
#include <bits/stdc++.h>
using namespace std;


// 2435


void solve()
{
    int n,m;
    cin >> n>>m;
    
    vector<vector<int>> arr(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>arr[i][j];

    int k;
    cin>>k;

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));

    dp[0][0][arr[0][0]%k]=1;

    int mod=1e9+7;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int r=0;r<k;r++)
            {
                if(i>0)
                {
                    int prev=(r-arr[i][j]%k + k)%k;
                    dp[i][j][r] = (dp[i][j][r] + dp[i-1][j][prev])%mod;
                }

                if(j>0)
                {
                    int prev=(r-arr[i][j]%k + k)%k;
                    dp[i][j][r] = (dp[i][j][r] + dp[i][j-1][prev])%mod;
                }
            }
        }
    }


    cout<<"The total path : "<<dp[n-1][m-1][0];





   
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}
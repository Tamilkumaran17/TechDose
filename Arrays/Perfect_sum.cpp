#include <bits/stdc++.h>
using namespace std;



int perfectSum(vector<int>& arr, int k) {
        // code here
        

        // using bitwise


        
        // int count=0;
        
        // int tot = 1<<arr.size();
        
        // for(int i=0;i<tot;i++)
        // {
        //     int sum=0;
        //     for(int j=0;j<arr.size();j++)
        //     {
        //         if(i & (1<<j))
        //         sum+=arr[j];
        //     }
            
        //     if(sum==k)
        //     count++;
        // }
        
        // return count;




        // using dp
        
        int n=arr.size();
        int mod =1e9+7;
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j] = dp[i-1][j];
                
                if(arr[i-1] <= j)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j- arr[i-1]])%mod;
                }
            }
        }
        
        return dp[n][k];
    }


    


void solve()
{

   int n;
   cin>>n;

   vector<int> arr(n);

   for(int &i:arr)
   cin>>i;

   int k;
   cin>>k;

   cout<<perfectSum(arr,k);




   

   

   

   
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
#include <bits/stdc++.h>
using namespace std;


// 239

void fun(int n, vector<int>& arr) {

    vector<int> dp(n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j])
            dp[i] = max( dp[i], dp[j]+1);
        }
    }

    cout<<*max_element(dp.begin(),dp.end());


    
}

void solve()
{

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

   

    


   fun(n,arr);

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
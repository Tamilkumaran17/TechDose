#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int>&arr, int idx, int tar, int currsum, vector<int>&curr, vector<vector<int>>& ans, int k)
{
    if(tar==currsum && curr.size() == k)
    {
        ans.push_back(curr);
        return;
    }

    if(idx >= arr.size() || tar < currsum || curr.size() > k )
    return;

    curr.push_back(arr[idx]);
    dfs(arr, idx+1, tar, currsum+arr[idx], curr,ans,k);
    curr.pop_back();
    dfs(arr, idx+1, tar, currsum,curr,ans,k);
}



vector<vector<int>> perfectSum(vector<int>& arr, int target, int k) {


    vector<vector<int>> ans;

    vector<int> curr;

    dfs(arr, 0 , target, 0, curr, ans, k );

    return ans;
}

    


void solve()
{

   int n;
   cin>>n;

   vector<int> arr(n);

   for(int &i:arr)
   cin>>i;

   int target;
   cin>>target;

   int k;
   cin>>k;

   vector<vector<int>> ans=perfectSum(arr,target,k);

   for(int i=0;i<ans.size();i++)
   {cout<<"{ ";
    for(int j=0;j<ans[i].size();j++)
    {
        if((j+1) != ans[i].size())
        cout<<ans[i][j]<<", ";
        else cout<<ans[i][j];
    }
    cout<<" } ";
   }




   

   

   

   
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
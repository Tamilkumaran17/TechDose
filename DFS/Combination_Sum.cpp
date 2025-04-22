#include <bits/stdc++.h>
using namespace std;


//39



void backtrack(vector<int>& arr, int k, int st,vector<int>& curr, vector<vector<int>>& ans)
{
    if(k==0)
    {
        ans.push_back(curr);
        return ;
    }
    else if(k<0)
    return ;
    

    for(int i=st;i<=arr.size();i++)
    {
        curr.push_back(arr[i]);
        backtrack(arr,k-arr[i],i,curr,ans);
        curr.pop_back();
    }
}


void solve()
{
    int n,k;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cin>>k;

    vector<int> curr;
    vector<vector<int>> ans;

    backtrack(arr,k,0,curr,ans);

    for(int i=0;i<ans.size();i++)
    { cout<<"[ ";
        for(int j=0;j<ans[0].size();j++)
        {
            if(ans[i][j]!=0)
            cout<<ans[i][j]<<" ";
        }
        cout<<"] \n";
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
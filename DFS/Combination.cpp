#include <bits/stdc++.h>
using namespace std;


//77



void backtrack(int n, int k, int st,vector<int>& curr, vector<vector<int>>& ans)
{
    if(curr.size()==k)
    {
        ans.push_back(curr);
        return ;
    }

    for(int i=st;i<=n;i++)
    {
        curr.push_back(i);
        backtrack(n,k,i+1,curr,ans);
        curr.pop_back();
    }
}


void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> curr;
    vector<vector<int>> ans;

    backtrack(n,k,1,curr,ans);

    for(int i=0;i<ans.size();i++)
    { cout<<"[ ";
        for(int j=0;j<k;j++)
        {
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
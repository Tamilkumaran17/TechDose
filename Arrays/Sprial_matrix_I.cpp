#include <bits/stdc++.h>
using namespace std;


void st()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>arr[i][j];

    vector<int> ans;

    int top=0,left=0,right=m-1,bottom=n-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        ans.push_back(arr[top][i]);

        top++;

        for(int i=top;i<=bottom;i++)
        ans.push_back(arr[i][right]);

        right--;

        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            ans.push_back(arr[bottom][i]);

            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            ans.push_back(arr[i][left]);

            left++;
        }
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
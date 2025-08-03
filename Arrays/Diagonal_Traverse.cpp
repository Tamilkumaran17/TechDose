#include <bits/stdc++.h>
using namespace std;

//498

void st()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>arr[i][j];

    vector<int> ans;

    for(int d=0; d < n+m-1; d++)
    {
        if(d%2==0)
        {
            int row= min(d,n-1);
            int col= d-row;


            while (row>=0 && col<m)
            {
                /* code */
                ans.push_back(arr[row][col]);
                row--;
                col++;
            }
            
        }
        else{
            int col= min(d,m-1);
            int row=d-col;

            while (col>=0 && row<n)
            {
                /* code */
                ans.push_back(arr[row][col]);
                row++;
                col--;
            }
            
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
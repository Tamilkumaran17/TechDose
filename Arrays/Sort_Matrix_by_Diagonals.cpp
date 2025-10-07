#include <bits/stdc++.h>
using namespace std;

//  3446





void solve()
{

    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];

    for(int r=n-1; r>=0; r--)
    {
        vector<int> d;
        int x=r,y=0;

        while(x<n && y<n)
        {
            d.push_back(arr[x++][y++]);
        }

        sort(d.rbegin(),d.rend());

        x=r,y=0;

        for(int i:d)
        {
            arr[x++][y++]=i;
        }


    }

    for(int c=1;c<n;c++)
    {
        int x=0,y=c;
        vector<int> d;

        while(x<n && y<n)
        {
            d.push_back(arr[x++][y++]);
        }

        sort(d.begin(),d.end());

        x=0,y=c;

        for(int i:d)
        {
            arr[x++][y++]= i;
        }

        

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    

    



   
    
    


    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
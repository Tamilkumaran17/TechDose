#include <bits/stdc++.h>
using namespace std;


void st()
{
    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(n,0));

    

   

    int top=0,left=0,right=n-1,bottom=n-1;

    int val=1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        arr[top][i]=val++;

        top++;

        for(int i=top;i<=bottom;i++)
        arr[i][right]=val++;

        right--;

        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            arr[bottom][i]=val++;

            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            arr[i][left]=val++;

            left++;
        }
    }

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
    }

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
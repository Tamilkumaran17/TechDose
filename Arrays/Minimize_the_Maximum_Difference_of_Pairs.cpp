#include <bits/stdc++.h>
using namespace std;


//2616


bool can_make_pair(vector<int>& arr,int maxx,int p)
{
    int c=0,i=0,n=arr.size();

    while(i<n-1)
    {
        if(arr[i+1]-arr[i]<=maxx)
        {
            c++;
            i+=2;
        }
        else
        i++;
    }
    return c>=p;
}



void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) 
    cin>>arr[i];

    int p;
    cin>>p;

    sort(arr.begin(),arr.end());

    int low=0,high=arr.back()-arr.front();

    int ans=high;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(can_make_pair(arr,mid,p))
        {
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }

    cout<<ans;

   
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
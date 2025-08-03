#include <bits/stdc++.h>
using namespace std;


// 239

long long cal_total(vector<int>&arr, int h)
{
    long long tot=0;

    for(int i:arr)
    {
        tot+= ceil( (double)i/ (double)h );
    }

    return tot;
}

void fun(int n, vector<int>& arr,int h) {

    int left=0;
    int right= *max_element(arr.begin(),arr.end());

    while(left<=right)
    {
        int mid=(left+right)/2;

        long long total = cal_total(arr,mid);

        if(total <= h)
        right=mid-1;
        else
        left=mid+1;
    }

    cout<<left;


    
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

    


   fun(n,arr,k);

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
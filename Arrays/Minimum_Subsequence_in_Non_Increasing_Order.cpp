#include <bits/stdc++.h>
using namespace std;


void st()
{
    vector<int> ans;

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i:arr)
    cin>>i;

    sort(arr.begin(),arr.end());
    int tot=accumulate(arr.begin(),arr.end(),0);

    int curr=0;

    for(int i=n-1;i>=0;i--)
    {
        curr+=arr[i];
        ans.push_back(arr[i]);

        if(curr > tot-curr)
        break;
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
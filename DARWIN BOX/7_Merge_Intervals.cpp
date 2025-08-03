#include <bits/stdc++.h>
using namespace std;


// 239


void fun(int n, vector<vector<int>>& arr) {

    if(n==0)
    cout<<" {} ";

    sort(arr.begin(),arr.end());

    vector<vector<int>> ans;


    ans.push_back({arr[0]});

    for(int i=1;i<n;i++)
    {
        vector<int> &last=ans.back();

        if(last[1] >= arr[i][0])
        last[1] = max(last[1], arr[i][1]);
        else
        ans.push_back(arr[i]);

    }

    for(auto i:ans)
    {
        cout<<"[ "<<i[0]<<","<<i[1]<<" ]\n";
    }

    

    
    
}

void solve()
{

    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(2,0));
    for(auto &i:arr)
    cin>>i[0]>>i[1];
    

    


   fun(n,arr);

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
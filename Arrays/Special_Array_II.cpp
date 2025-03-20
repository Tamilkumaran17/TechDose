#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

    int m;
    cin>>m;
    vector<vector<int>> queries(m,vector<int>(2,0));

    for(int i=0;i<m;i++)
    cin>>queries[i][0]>>queries[i][1];

    vector<int> prefix(n,0);
    vector<int> ans(m,false);


    for(int i=1;i<n;i++)
    {
        if(arr[i]%2==arr[i-1]%2)
        prefix[i]=prefix[i-1]+1;

        else
        prefix[i]=prefix[i-1];
    }

    for(int i=0;i<m;i++)
    {
        vector<int> q=queries[i];
        int start=q[0], end=q[1];

        ans[i] = prefix[end]-prefix[start]==0;
    }

    cout<<"[";
    for(int i=0;i<m;i++)
    {
        cout << (ans[i] ? "true" : "false");
        if (i < m - 1) cout << ", ";
    }
    cout<<"]";
    

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    


}
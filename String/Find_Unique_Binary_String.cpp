#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    cin >> n;
    
    vector<string> arr;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr.push_back({s});
    }

    string ans;

    for(int i=0;i<n;i++)
    {
        char curr=arr[i][i];
        ans+= curr=='0' ? '1' : '0';
    }

    cout<<"Find Unique Binary String "<<ans;
   
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
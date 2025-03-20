#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    int k;
    cin>>k;

    int i=0,ans=INT_MAX;
    unordered_map<int,int> mp;

    for(int j=0;j<n;j++)
    {
        mp[arr[j]]++;

        if(mp.size() < k) 
        continue;

        while(mp.size()==k)
        {
            ans=min(ans, j-i+1);

            mp[arr[i]]--;

            if(mp[arr[i]]==0)
            mp.erase(arr[i]);

            i++;

        }
    }

    cout<< "The Minimum length of subarray with unique values is "<< ans;


    
    
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
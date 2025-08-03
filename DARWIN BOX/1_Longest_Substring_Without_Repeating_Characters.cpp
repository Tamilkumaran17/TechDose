#include <bits/stdc++.h>
using namespace std;


//


int fun(string s) {
    int n=s.size();

    int left=0,ans=INT_MIN;
    unordered_map<int,int> mp;
    string sub="";

    for(int right=0;right<n;right++)
    {
        

        if(mp.find(s[right])!=mp.end())
        {
            left =max(left, mp[s[right]]+1);

        }

        mp[s[right]]++;

        if(ans < right-left+1)
        {
            sub=s.substr(left,ans+1);
            ans= max(ans,right-left+1);
        }
    }
    cout<<sub<<endl;

    return ans;
    
}

void solve()
{

   string s;
   cin>>s;

   cout<< fun(s);

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
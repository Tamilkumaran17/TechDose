#include <bits/stdc++.h>
using namespace std;

bool check(string s, int tar, int idx,int curr)
{
    if(idx==s.size())
    return curr==tar;

    int sum=0;

    for(int i=idx;i<s.size();i++)
    {
        sum = sum*10 + (s[i]-'0');

        if(sum+curr > tar )
        break;

        if(check(s, tar, i+1, sum+curr))
        return true;

    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int squared = i*i;
        string str = to_string(squared);

        if(check( str, i, 0, 0))
        sum+=squared;
    }
    
    cout<<"The sum of punishment numbers upto "<<n<<" is "<<sum;
   
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
#include <bits/stdc++.h>
using namespace std;


//3443 leetcode

void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    
    int k;
    cin>>k;

    int lat=0, lon=0, ans=0;

    for(int i=0;i<n;i++)
    {
        switch(s[i])
        {
            case 'N':
                lat++;
                break;
            case 'S':
                lat--;
                break;
            case 'E':
                lon++;
                break;
            case 'W':
                lon--;
                break;
        }

        ans = max(ans, min( abs(lat)+abs(lon) + k * 2, i+1));
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
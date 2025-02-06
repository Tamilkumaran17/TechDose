#include <bits/stdc++.h>
using namespace std;

void solve_in_brute()
{
    string s;
    int k;
    cin>>s>>k;

    int maxx=0;
    map<char,int> mp;
    int n=s.size();

    for(int i=0;i<n;i++)
    {
        mp.clear();

        for(int j=i;j<n;j++)
        {
            mp[s[j]]++;

            if(mp.size()<=k)
            {
                maxx=max(maxx, j-i+1);
            }
            else
            break;

        }
    }

    cout<<maxx;
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve_in_brute();

    return 0;

}
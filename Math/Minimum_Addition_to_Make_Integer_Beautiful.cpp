#include <bits/stdc++.h>
using namespace std;

//  2457



long long sumup(long long n)
{
    long long sum=0;

    while(n)
    {
        sum+= n%10;
        n/=10;
    }
    return sum;
}

void solve()
{

    long long n;
    cin>>n;

    int target;
    cin>>target;


    if(sumup(n) <= target)
    {
        cout<<0;
        return;
    }

    long long mul=1, ans=0;

    while( sumup(n) > target)
    {
        long long rem= n % (mul * 10);
        long long toAdd= (mul * 10) - rem;

        n+= toAdd;
        ans+= toAdd;
        mul*=10;
    }

    cout<<ans;



   
    
    


    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
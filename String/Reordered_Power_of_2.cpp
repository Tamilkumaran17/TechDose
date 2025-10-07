#include <bits/stdc++.h>
using namespace std;

//  869



void solve()
{

    int n;
    cin>>n;

    string s=to_string(n);

    sort(s.begin(),s.end());

    int flag=0;

    for(int i=0;i<=29;i++)
    {
        int power= 1<<i;
        string p= to_string(power);

        sort(p.begin(),p.end());

        if(s==p)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    cout<<"True";
    else cout<< "False";

    
    
    
    


    
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
#include <bits/stdc++.h>
using namespace std;



void solve()
{
    
    string pattern;
    cin>>pattern;

    string ans;
    stack<int> num;

    for(int i=0;i<=pattern.size();i++)
    {
        num.push(i+1);

        if(pattern[i]=='I' || i==pattern.size())
        {
            while(!num.empty())
            {
                ans+=to_string(num.top());
                num.pop();
            }
        }


    }
    cout<<" The output is " << ans;

   
   
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
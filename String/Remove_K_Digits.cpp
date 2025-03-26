#include <bits/stdc++.h>
using namespace std;


// 402

// Given string num representing a non-negative integer num, and an integer k, 
// return the smallest possible integer after removing k digits from num.

void solve()
{
    string s;
    cin>>s; 

    int k;
    cin>>k;


    string ans="";

    for(char &ch:s)
    {
        while(ans.size() && ans.back() > ch && k)
        {
            ans.pop_back();
            k--;
        }


        if(ans.size() || ch!='0')
        ans.push_back(ch);
    }

    while(ans.size() && k--)
    ans.pop_back();

    cout<<"the smallest possible integer after removing k digits from num " << ans <<endl;
   
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
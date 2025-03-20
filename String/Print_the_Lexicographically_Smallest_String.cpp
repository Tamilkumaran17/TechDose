#include <bits/stdc++.h>
using namespace std;


//2434 leetcode

void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    vector<char> suffix(n);

    suffix[n-1]=s[n-1];

    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=min(suffix[i+1],s[i]);
    }

    string t="",p="";

    int idx=0;

    while (idx<n)
    {
        /* code */

        if(t.empty())
        {
            t.push_back(s[idx++]);
            continue;
        }

        if(suffix[idx] < t.back())
        {
            char req=suffix[idx];

            while (s[idx] != req)
            {
                t.push_back(s[idx++]);
                
            }
            t.push_back(s[idx++]);
            
        }

        p+=t.back();
        t.pop_back();
    }

    while(!t.empty())
    {
        p+=t.back();
        t.pop_back();
    }


    cout<<"The Lexicographically Smallest String written in the paper is : "<< p;
    
   
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
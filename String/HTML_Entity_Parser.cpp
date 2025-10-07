#include <bits/stdc++.h>
using namespace std;

//  1410

string entityParser(string text) {
        
        unordered_map<string,string> mp={
            {"&quot;","\""},
            {"&apos;","'"},
            {"&amp;","&"},
            {"&gt;",">"},
            {"&lt;","<"},
            {"&frasl;","/"},
        };

        int n=text.size();
        string ans;

        for(int i=0;i<n;i++)
        {
            if(text[i]=='&')
            {
                bool replace = false;

                for(int len=4; len <= 7 && i+len <= n; len++)
                {
                    string sub= text.substr(i,len);

                    if(mp.count(sub))
                    {
                        ans+= mp[sub];

                        i+= len-1;

                        replace=true;
                        break;
                    }
                }

                if(!replace)
                ans+=text[i];
            }
            else
            ans+= text[i];
        }

        return ans;
        
    }



void solve()
{


    string s;
    getline(cin,s);
    cout<<entityParser(s);


   
    
    


    
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
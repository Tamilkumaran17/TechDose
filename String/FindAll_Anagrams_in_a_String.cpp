#include <bits/stdc++.h>
using namespace std;

// 

void solve()
{

    string s,p;
    cin>>s>>p;

    int ns= s.size(), np = p.size();

        if( ns < np)
        cout<<"{}";

        vector<int> ans;
        vector<int> p_freq(26,0), s_freq(26,0);
        

        for(char ch: p)
        p_freq[ch-'a']++;

        for(int i=0;i<np;i++)
        s_freq[s[i]-'a']++;

        if(s_freq == p_freq)
        ans.push_back(0);

        for(int i=np;i<ns;i++)
        {
            s_freq[s[i]-'a']++;
            s_freq[s[i - np] -'a']--;

            if(s_freq == p_freq)
            ans.push_back(i-np+1);
        }
        
        cout<<"[";
        for(int i=0;i<ans.size();i++)
        {
            if(i!=ans.size()-1)
            cout<<ans[i]<<",";
            else
            cout<<ans[i];
        }
        cout<<"]";

    


    
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
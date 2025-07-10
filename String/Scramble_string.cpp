#include <bits/stdc++.h>
using namespace std;


//87 leetcode

unordered_map<string, bool> mp;

bool scramble(string a,string b)
{

    if(a==b)
    return true;

    if(a.size()==1)
    return a==b;

    string key= a+b;

    if(mp.find(key) != mp.end())
    return mp[key];

    vector<int> f1(26), f2(26);

    for(int i=0;i<a.size();i++)
    {
        f1[a[i]-'a']++;
        f2[b[i]-'a']++;
    }

    if(f1!=f2)
    return mp[key] = false;
    int n=a.size();


    for(int i=1;i<a.size();i++)
    {
        if( ( scramble(a.substr(0,i), b.substr(0,i)) && scramble(a.substr(i), b.substr(i))  ) || 
            ( scramble(a.substr(0,i), b.substr(n-i)) && scramble(a.substr(i), b.substr(0,n-i)) ))
            return mp[key]=true;

    }

    return mp[key]=false;

    

}

void solve()
{
    string s1,s2;
    cin>>s1>>s2;

    if(scramble(s1,s2))
    cout<<"True";
    else cout<<"False";

    
    
   
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
#include <bits/stdc++.h>
using namespace std;

//  Given two integers n and k, split the number n into exactly k positive integers such that the product of these integers is equal to n.
// Return any one split in which the maximum difference between any two numbers is minimized. You may return the result in any order.
// Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

int best=INT_MAX;
vector<int> result;

void dfs(int n, int k,vector<int>& curr,int st)
{
    if(k==1)
    {
        curr.push_back(n);

        int maxx=*max_element(curr.begin(),curr.end());
        int minn=*min_element(curr.begin(),curr.end());

        int diff=maxx-minn;

        if(diff < best)
        {
            result=curr;
            best=diff;
        }

        curr.pop_back();

        return;
    }

    for(int i=st;i*i<=n;i++)
    {
        if(n%i==0)
        {
            curr.push_back(i);
            dfs(n/i,k-1,curr,i);
            curr.pop_back();
        }
    }
}

vector<int> min_dif(int n,int k)
{
    vector<int> curr;

    dfs(n,k,curr,1);

    return result;

}

void solve()
{

    int n;
    cin>>n;

    int k;
    cin>>k;

    // vector<int> curr;
    vector<int> ans=min_dif(n,k);
    
    for(int i:ans)
    cout<<i<<" ";


    

    

    



   
    
    


    
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
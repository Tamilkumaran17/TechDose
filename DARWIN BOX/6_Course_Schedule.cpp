#include <bits/stdc++.h>
using namespace std;


// 


void fun(int numcrc, vector<vector<int>>& arr,int n) {

   vector<vector<int>> adj(numcrc);

   for(auto &i:arr)
   adj[i[1]].push_back(i[0]);

   vector<int> indegree(numcrc,0);

   for(int i=0;i<numcrc;i++)
   {
    for(auto &j: adj[i])
    {
        indegree[j]++;
    }
   }

   queue<int> q;

   for(int i=0;i<numcrc;i++)
   {
    if(indegree[i]==0)
    {
        q.push(i);
    }
   }

   int c=0;

   while(!q.empty())
   {
    auto node = q.front();
    q.pop();

    c++;

    for(auto i:adj[node])
    {
        indegree[i]--;
        if(indegree[i]==0)
        q.push(i);
    }
   }

   if(c==numcrc)
   cout<< "TRUE";
   else
   cout<<"FALSE";


    
}

void solve()
{
    int numcrc;
    cin>>numcrc;

    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
        }
    }
    

    


   fun(numcrc,arr,n);

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
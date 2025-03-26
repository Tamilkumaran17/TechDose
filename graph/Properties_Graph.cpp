#include <bits/stdc++.h>
using namespace std;



//3493

// ou are given a 2D integer array properties having dimensions n x m and an integer k.
// Define a function intersect(a, b) that returns the number of distinct integers common to both arrays a and b.
// Construct an undirected graph where each index i corresponds to properties[i]. There is an edge between node i and node j if and only if intersect(properties[i], properties[j]) >= k, where i and j are in the range [0, n - 1] and i != j.
// Return the number of connected components in the resulting graph.

int intersect(vector<int>& arr1, vector<int>& arr2)
{
    int c=0;

    unordered_map<int,int> mp;

    for(int i:arr1)
    {
        if(mp[i] > 0)
        continue;

        mp[i]++;
    }

    for(int i:arr2)
    {
        if(mp[i] > 0 )
        {
            c++;
            mp[i]--;
        }
    }

    return c;
}

vector<vector<int>> adj;
void dfs(int node, vector<bool>& visited)
{
    visited[node]=true;
    
    for(int i:adj[node])
    {  
        if(!visited[i])
        dfs(i,visited);
    }

    
}
void solve()
{

    
    int k=2;
    

    vector<vector<int>> arr={{1,2,3},{2,3,4},{4,3,5}};
    int n=arr.size();

    int ans=0;

    adj.resize(n,vector<int>());

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
            
            if(intersect(arr[i],arr[j]) >= k){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n,false);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans++;            
            dfs(i,visited);
           
        }
    }

    cout<<ans;



   
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
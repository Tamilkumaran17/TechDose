#include <bits/stdc++.h>
using namespace std;



//2685

vector<vector<int>> adj;
void dfs(int node, unordered_set<int>& nodes, int& edge, vector<bool>& visited)
{
    visited[node]=true;
    nodes.insert(node);

    for(int i:adj[node])
    {

        edge++;
        if(!visited[i])
        dfs(i,nodes,edge,visited);
    }

    
}
void solve()
{

    int n=6;
    

    vector<vector<int>> arr={{0,1},{0,2},{1,2},{3,4}};

    int ans=0;

    adj.resize(n,vector<int>());

    for(auto& i:arr)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> visited(n,false);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int> nodes;
            int edge=0;

            dfs(i,nodes,edge,visited);

            int k=nodes.size();
            if( (k*(k-1))/2==edge/2)
            ans++;
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
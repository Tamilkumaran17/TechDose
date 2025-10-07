#include <bits/stdc++.h>
using namespace std;

// 

void solve()
{

    

    vector<vector<int>> rooms = {
    {1, 3},
    {3, 0, 1},
    {2},
    {0}
    };

    int n=rooms.size();

    vector<bool> visited(n,false);
        visited[0]=true;
        
        stack<int> st;
        st.push(0);

        while(!st.empty())
        {
            int node =st.top();
            st.pop();

            for(int i:rooms[node])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    st.push(i);
                }
            }
        }
        
        int flag=1;
        for(bool i:visited)
        if(!i)
        flag=0;

        cout<<(flag==1) ? "true" : "false";



    
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
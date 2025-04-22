#include <bits/stdc++.h>
using namespace std;


//2503

#define pii pair<int,int>
#define pip pair<int, pii>

vector<int> all_count(vector<vector<int>>& arr, vector<int>& queries)
{
    int m=arr.size();
    int n=arr[0].size();

    // vector<int> q_sorted=queries;
    // sort(q_sorted.begin(),q_sorted.end());

    set<int> q_sorted(queries.begin(),queries.end());

    unordered_map<int,int> q_count;
    priority_queue<pip, vector<pip> , greater<pip>> minheap;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<int> dir={-1,0,1,0,-1};

    minheap.push( make_pair(arr[0][0], make_pair(0,0)));
    visited[0][0]=true;

    int c=0;

    for(int q:q_sorted)
    {

        while (!minheap.empty())
        {
            auto curr = minheap.top();
            minheap.pop();

            int val=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;

            if(val >= q)
            {
                minheap.push(curr);
                break;
            }

            c++;

            for(int i=0;i<4;i++)
            {
                int nx= x+dir[i];
                int ny= y+dir[i+1];

                if( nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny])
                {
                    visited[nx][ny]= true;
                    minheap.push( make_pair( arr[nx][ny], make_pair(nx,ny)));
                }
            }

        }

        q_count[q]=c;
        
    }

    vector<int> ans;
    for(int i:queries)
    ans.push_back(q_count[i]);

    return ans;

}

void solve()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];

    int k;
    cin>>k;

    vector<int> queries(k);
    for(int i=0;i<k;i++)
    cin>>queries[i];

    // vector<vector<int>> arr={{1,2,3}, {2,5,7}, {3,5,6}};
    // vector<int> queries = {5,6,2};

    vector<int> ans = all_count(arr,queries);

    for(int i:ans)
    {
        cout<<i<<" ";
    }
   


   
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
#include <bits/stdc++.h>
using namespace std;


// subarray sum == k not subset ex: [1 2 1 3] , op: 3 { [1 2], [2 1], [3]}


void fun(vector<int>& arr,int k) {



    int n=arr.size();
    unordered_map<int,int> prefix_count;

    prefix_count[0]=1;

    int prefix=0;
    int count=0;

    for(int i=0;i<n;i++)
    {
        prefix+=arr[i];
        

        if( prefix_count.find( prefix-k) != prefix_count.end())
        count += prefix_count[prefix-k];

        prefix_count[prefix]++;
    }

    cout<<count;





    // **** same question if need to return the subarray also means;  ****


    int N= arr.size();
    unordered_map<int, vector<int>> prefix_sum;
    prefix_sum[0] ={-1};

    vector<vector<int>> ans;

    int Prefix = 0 ,Count=0;

    for(int i=0;i<N;i++)
    {
        Prefix+=arr[i];

        if(prefix_sum.count(Prefix-k))
        {
            for(int sub: prefix_sum[Prefix - k])
            {
                vector<int> subarray(arr.begin() + sub+1, arr.begin() + i+1);
                ans.push_back(subarray);

            }
        }

        prefix_sum[Prefix].push_back(i);
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++)
        {
            if(j!=ans[i].size())
            cout<<ans[i][j]<<" ";
            else
            cout<<ans[i][j];
        }
        cout<<"]"<<endl;
    }




    
    
}

void solve()
{

   int n;
   cin>>n;

   vector<int> arr(n);
   
   for(int &i:arr)
   cin>>i;

   int k;
   cin>>k;

   fun(arr,k);

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
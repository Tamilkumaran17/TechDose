#include <bits/stdc++.h>
using namespace std;


//1232



bool check(vector<vector<int>>& nums)
{
    int n=nums.size();
    int dx= nums[1][0] - nums[0][0];
    int dy= nums[1][1] - nums[0][1];

    for(int i=2;i<n;i++)
    {

        auto p=nums[i];

        if( dx * (p[1] - nums[0][1]) != dy * (p[0] - nums[0][0]))
        return false;
    }
    return true;
    


    
}

void solve()
{

   int n;
   cin>> n;

   vector<vector<int>> arr;

   for(int i=0;i<n;i++)
   {
    int x,y;
    cin>>x>>y;
    arr.push_back({x,y});
   }
   


   cout << (check(arr) ? "true" : "false");

   

   
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
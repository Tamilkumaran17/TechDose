#include <bits/stdc++.h>
using namespace std;


//1266




void solve()
{

   int n;
   cin>> n;

   vector<vector<int>> arr(n,vector<int>(2,0));

   for(int i=0;i<n;i++)
   {
    for(int j=0;j<2;j++)
    {
        cin>>arr[i][j];
    }

   }

   int ans=0;

   auto generate = [&](vector<int>& from, vector<int>& to)-> int{

    int x= abs(from[0]-to[0]);
    int y= abs(from[1]-to[1]);

    return max(x,y);
   };

   for(int i=1;i<n;i++)
   ans+= generate(arr[i-1], arr[i]);

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
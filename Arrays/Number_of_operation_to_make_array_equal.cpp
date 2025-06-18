#include <bits/stdc++.h>
using namespace std;


//1887



int count_operation(vector<int>& nums)
{
    int n=nums.size();
    int ans=0;

    sort(nums.begin(),nums.end());

    for(int i=n-1;i>0;i--)
    {
        if(nums[i] != nums[i-1])
        ans+= n-i;
    }

    return ans;
}

void solve()
{

   int n;
   cin>> n;

   vector<int> arr(n);

   for(int &i:arr)
   cin>>i;


   cout<< count_operation(arr);

   

   
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
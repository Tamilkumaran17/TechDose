#include <bits/stdc++.h>
using namespace std;


//3583



int count_triple(vector<int>& nums)
{
    int n=nums.size();
    unordered_map<int,int> left ,right;

    for(int i:nums)
    right[i]++;

    int ans=0;

    for(int i=0;i<n;i++)
    {
        right[nums[i]]--;

        int tar = nums[i] * 2;

        int l= left[tar];
        int r= right[tar];

        ans= (ans + (l*r));

        left[nums[i]]++;


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


   cout<< count_triple(arr);

   

   
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
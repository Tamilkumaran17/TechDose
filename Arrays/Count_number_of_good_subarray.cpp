#include <bits/stdc++.h>
using namespace std;


//2537



int count_subarray(vector<int>& nums,int k)
{
    int n=nums.size();
    unordered_map<int,int> mp;

    int pair=0,ans=0;

    int left=0;

    for(int right=0; right<n; right++)
    {
        pair += mp[nums[right]];
        mp[nums[right]]++;

        while(pair >= k )
        {
            ans += (n-right);

            mp[nums[left]]--;

            pair -= mp[nums[left]];

            left++;
        }
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

   int k;
   cin>>k;


   cout<< count_subarray(arr,k);

   

   
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
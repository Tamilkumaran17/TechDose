#include <bits/stdc++.h>
using namespace std;


//2762



int count_subarrays(vector<int>& nums)
{
    int n=nums.size();
    map<int,int> mp;
    int ans=0;
    int left=0;

    for(int right=0;right<n;right++)
    {
        mp[nums[right]]++;

        while( mp.rbegin()->first - mp.begin()->first > 2)
        {
            mp[nums[left]]--;

            if(mp[nums[left]]==0)
            mp.erase(nums[left]);

            left++;
        }

        ans+= (right - left + 1);
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


   cout<< count_subarrays(arr);

   

   
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
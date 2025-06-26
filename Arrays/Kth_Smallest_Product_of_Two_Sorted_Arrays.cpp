#include <bits/stdc++.h>
using namespace std;


//2040

long countpos(vector<int>& nums, int a, long long mid)
    {
        int left=0, right=nums.size();

        while(left < right)
        {
            int m = (left+right) / 2;

            if((long long) a * nums[m] <= mid )
            left = m+1;
            else
            right = m;
        }

        return left;
    }

    long countneg(vector<int>& nums, int a, long long mid)
    {
        int left=0, right=nums.size();

        while(left < right)
        {
            int m = (left+right) / 2;

            if((long long) a * nums[m] <= mid )
           right=m;
            else
            left=m+1;
        }

        return nums.size()-left;
    }

    long long count(vector<int>& nums1, vector<int>& nums2, long long mid)
    {
        long long c=0;
        for(int i:nums1)
        {

            if(i>=0)
            c+= countpos(nums2, i, mid);

            else 
            c+= countneg(nums2, i, mid);
        }

        return c;
    }
    long long Kth_Smallest_Product_of_Two_Sorted_Arrays(vector<int>& nums1, vector<int>& nums2, long long k) {

        long long left=-1e10, right=1e10;

        while(left < right)
        {
            long long mid = left + (right - left) / 2;

            if(count(nums1, nums2, mid) < k)
            left = mid+1;

            else
            right=mid;
        }

        return left;
        
    }




void solve()
{

   int n,m;
   cin>> n >> m;

   vector<int> nums1(n),nums2(m);

   for(int& i: nums1)
   cin>>i;

   for(int& i:nums2)
   cin>>i;

   int k;
   cin>>k;

   cout<< Kth_Smallest_Product_of_Two_Sorted_Arrays(nums1,nums2,k);



   

   

   

   
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
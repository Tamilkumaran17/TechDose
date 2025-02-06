#include <bits/stdc++.h>
using namespace std;

void trapping_rainWater(vector<int> &nums)
{     
    int n=nums.size();
    int left=0,right=n-1;
    int maxLeft=0,maxRight=0;
    int water=0;
    while(left<=right)
    {
        if(nums[left]<=nums[right])
        {
            if(nums[left]>=maxLeft)
            {
                maxLeft=nums[left];
                left++;
            }
            else
            {
               
                water+= maxLeft-nums[left];
                left++;
            }
        }
        else
        {
            if(nums[right]>=maxRight)
            {
                maxRight=nums[right];
                right--;
            }
            else
            {
                water+= maxRight- nums[right];
                right--;
            }
        }
    }

    cout<<water;
}

void st()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

    trapping_rainWater(arr);

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
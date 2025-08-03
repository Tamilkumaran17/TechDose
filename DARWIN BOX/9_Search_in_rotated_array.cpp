#include <bits/stdc++.h>
using namespace std;


// 239


void fun(int n, vector<int>& nums,int k) {

    // int left=0,right=n-1;
    // bool flag=false;

    // while(left <= right)
    // {
    //     int mid=(left+right)/2;

    //     if(nums[mid]==k)
    //     {
            
    //         {
    //             flag=true;
    //             break;
    //         }
    //     }

    //     if(nums[left] <= nums[mid])
    //     {
    //         if( k > nums[mid] || nums[left] > k)
    //         left=mid+1;

    //         else
    //         right =mid-1;
    //     }
    //     else{
    //         if(nums[mid] > k || nums[right] < k)
    //         right=mid-1;
    //         else
    //         left=mid+1;
    //     }
    // }

    // if(flag)
    // cout<<"TRUE";
    // else
    // cout<<"FALSE";




    // same but the array have duplicate values [1,1,1,3,4,4,5,6,6,6]

    int left=0,right=n-1;
    bool flag=false;


    while (left<=right)
    {
        /* code */
        int mid= (left+right)/2;

        if(nums[mid]==k)
        {
            flag=true;
            break;
        }

        if(nums[mid]==nums[left] && nums[mid]==nums[right])
        {
            left++;
            right--;
        }

        if(nums[left] <= nums[mid])
        {

            if(nums[mid] >= k && nums[left] < k)
            left=mid+1;
            else
            right=mid-1;
        }
        else{
            if(nums[mid] <= k && nums[right] > k)
            right=mid-1;
            else
            left=mid+1;
        }
    }

    if(flag)
    cout<<"TRUE";
    else
    cout<<"FALSE";
    



    



    
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

    


   fun(n,arr,k);

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
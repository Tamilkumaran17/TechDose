#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int k;
    cin>>k;

    vector<int> nums(k);  //[1,1,0,1]
    for(int i=0;i<k;i++)
    cin>>nums[i];

    int left=0,zero=0,maxx=0;

    for(int right=0;right<k;right++)
    {
        if(nums[right]==0)
        zero++;

        while(zero>1)
        {
            if(nums[left]==0)
            zero--;
        }

        maxx=max( maxx, right-left);
    }

    cout<<maxx;



   
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
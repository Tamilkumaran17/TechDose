#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    int goal;
    cin>>goal;


    function<int(int)> fun = [&](int goal)
    {
        int l=0,r=0,sum=0,count=0;

        if(goal  < 0)
        return 0;

        while(r < n)
        {
            sum+=arr[r];

            while(sum > goal)
            {
                sum-=arr[l++];
            }

            count+= (r-l+1);
            r++;
        }
        return count; 
    };

    cout<<" The Binary subarray with sum equal to goal "<< goal << " is : || " << fun(goal) - fun(goal -1) << " ||" <<endl;


    


   
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
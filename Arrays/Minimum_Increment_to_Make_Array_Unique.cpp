#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(begin(arr),end(arr));
    
    int op=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i] <= arr[i-1])
        {
            int inc=arr[i-1] - arr[i] + 1;
            arr[i]+=inc;
            op+=inc;

        }
    }
    cout<<"Min operations to make the array unique is "<< op;
   
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
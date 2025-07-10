#include <bits/stdc++.h>
using namespace std;


//1751


// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. 
// The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei.
//  You are also given an integer k which represents the maximum number of events you can attend.

// You can only attend one event at a time. 
// If you choose to attend an event, you must attend the entire event.
//  Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

// Return the maximum sum of values that you can receive by attending events.




vector<vector<int>> memo;
vector<int> next_event;
int fun(vector<vector<int>> & arr,int k,int pos, int n)
{
    if(pos>= n || k==0)
    return 0;
    if(memo[pos][k]!=-1)
    return memo[pos][k];

    int skip = fun(arr, k, pos+1, n);

    int next_pos = next_event[pos];

    int attended = fun(arr,k-1,next_pos,n)+arr[pos][2];

    return memo[pos][k] = max(skip,attended);
    
    

}

void solve()
{

   int n;
   cin>> n;

   vector<vector<int>> arr(n,vector<int>(3,0));

   for(int i=0;i<n;i++)
   cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
   int k;
   cin>>k;

    sort(arr.begin(),arr.end());

    memo.resize(n,vector<int>(k+1,-1));

    next_event = vector<int>(n);

    for(int i=0;i<n;i++)
    {
        next_event[i] = upper_bound(arr.begin()+i , arr.end(), vector<int>{arr[i][1],0,0}) - arr.begin();

    }
    cout<< fun(arr,k,0,n);



   
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
#include <bits/stdc++.h>
using namespace std;


//1353


// You are given an array of events where events[i] = [startDayi, endDayi]. 
// Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startDayi <= d <= endDayi. 
// You can only attend one event at any time d.

// Return the maximum number of events you can attend.



int fun(vector<vector<int>> & arr)
{
    sort(arr.begin(),arr.end());

    int n=arr.size(), pos=0,time=1,attend=0;

    priority_queue< int, vector<int> ,greater<int>> minheap;

    while ( pos < n || !minheap.empty())
    {
        /* code */

        if(minheap.empty())
        {
            time = max(time, arr[pos][0]);
        }

        while( pos < n && arr[pos][0] == time)
        minheap.push({arr[pos++][1]});

        while(!minheap.empty() && minheap.top() < time)
        minheap.pop();

        if(!minheap.empty())
        {
            minheap.pop();
            attend++;
        }
        time++;
    }

    return attend;
    

}

void solve()
{

   int n;
   cin>> n;

   vector<vector<int>> arr(n,vector<int>(2,0));

   for(int i=0;i<n;i++)
   cin>>arr[i][0]>>arr[i][1];

   cout<<fun(arr);

   
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
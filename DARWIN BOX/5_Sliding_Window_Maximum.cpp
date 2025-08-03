#include <bits/stdc++.h>
using namespace std;


// 239


void fun(int n, vector<int>& arr,int k) {

    vector<int> ans;

    deque<int> dq;

    for(int i=0;i<n;i++)
    {
        if(!dq.empty() && dq.front() == i-k)
        dq.pop_front();

        while( !dq.empty() && arr[dq.back()] < arr[i])
        dq.pop_back();

        dq.push_back(i);

        if( i>= k-1)
        ans.push_back(arr[dq.front()]);
    }

    for(int i:ans)
    cout<<i<<" ";
    
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
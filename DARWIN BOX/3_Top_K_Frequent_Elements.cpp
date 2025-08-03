#include <bits/stdc++.h>
using namespace std;


// 


void fun(int n, vector<int>& arr, int k) {

    unordered_map<int,int> mp;
    for(int i:arr)
    mp[i]++;

    priority_queue< pair<int,int> ,  vector<pair<int,int>> , greater<>> pq;


    for(auto [ num, count] : mp)
    {
        pq.push({count, num});
        if(pq.size() > k)
        pq.pop();
    }

    while(!pq.empty())
    {
        cout<<"Number "<< pq.top().second <<" appears "<< pq.top().first <<" time's\n";
        pq.pop();
    }
    
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
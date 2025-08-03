#include <bits/stdc++.h>
using namespace std;

//2210


void st()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int&i:arr)
    cin>>i;

    vector<int> set;

    set.push_back(arr[0]);

    for(int i=1;i<n;i++)
    if(arr[i]!=arr[i-1])
    set.push_back(arr[i]);

    int count=0;

    for(int i=1; i<set.size()-1; i++)
    {
        if(set[i] < set[i-1] && set[i] < set[i+1] )
        count++;

        if(set[i] > set[i-1] && set[i] > set[i+1])
        count++;
    }

    cout<<count;

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
#include <bits/stdc++.h>
using namespace std;


// 729


void fun(int n, vector<int>& arr) {

    vector<int> ans(n,0);

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }

        st.push(i);
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

    


   fun(n,arr);

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
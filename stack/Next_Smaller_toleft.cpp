#include <bits/stdc++.h>
using namespace std;



void next_smaller_toleft(vector<int> &nums)
{     
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=2*n-1;i>=0;i--)
    {
        int curr= nums[i%n];

        while(!st.empty() && nums[st.top()] >= curr)
        {
            ans[st.top()]=curr;
            st.pop();
        }
        if(i<n)
        st.push(i);
    }

    for(int i:ans)
    cout<<i<<" ";
        
}



void st()
{
    

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

    next_smaller_toleft(arr);

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
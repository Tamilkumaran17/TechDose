#include <bits/stdc++.h>
using namespace std;



void next_greater(vector<int> &nums)
{     
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0;i<2*n;i++)
    {
        int curr= nums[i%n];

        while(!st.empty() && nums[st.top()] < curr)
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

    next_greater(arr);

    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
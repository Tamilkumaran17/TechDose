#include <bits/stdc++.h>
using namespace std;



void Asteriod_collision(vector<int> &nums)
{     
    int n=nums.size();
   
    vector<int> st;

    for(int i=0; i<n;i++)
    {
        if(nums[i] > 0)
        st.push_back(nums[i]);

        else{
            
            while(!st.empty() &&  st.back() > 0 && st.back() < abs(nums[i]))
            st.pop_back();

            if(!st.empty() && st.back()==abs(nums[i]))
            st.pop_back();

            else if( st.empty() || st.back() < 0)
            st.push_back(nums[i]);
        }
    }
    for(int i=0;i<st.size();i++)
    cout<<st[i]<<" ";
    
}

void st()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i:arr)
    cin>>i;

    Asteriod_collision(arr);

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}
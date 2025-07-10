#include <bits/stdc++.h>
using namespace std;







void solve()
{

    // 1st

   int n;
   cin>> n;

   vector<int> arr(n);

   for(int &i:arr)
   cin>>i;

//    stack<pair<int,int>> st;
//    if(n==1)
//    {
//     if(arr[0]%2==0)
//     cout<<"Even"<<endl;
//     else cout<<"Odd"<<endl;
//    }

//    else{
//     st.push({arr[0] ^ arr[1], 0});

//     for(int i=2;i<n;i++)
//     {
//         auto [val,op] = st.top();
//         st.pop();

//         int nn=0;

//         if(op==0)
//         {
//             nn=(val & arr[i]);
//             st.push({nn,1});
//         }
//         else if(op==1)
//         {
//             nn=(val | arr[i]);
//             st.push({nn,2});
//         }
//         else if(op==2)
//         {
//             nn=(val ^ arr[i]);
//             st.push({nn,0});
//         }
//     }

//     int val = st.top().first;
//     st.pop();

//     if(val%2==0)
//     cout<<"Even"<<endl;
//     else cout<<"Odd"<<endl;
//    }


        // using recursion;

        // [4 5 1 2 3]

        function<void(int,vector<int>&,vector<int>&,int&)>  recur = [&](int idx, vector<int>&arr,vector<int>&nums,int& ans)
        {
            if(idx==arr.size())
            {
                if(nums.empty())
                return;

                int val=nums[0];

                for(int i=1;i<nums.size();i++)
                {
                    if(i%3==1)
                    val ^=nums[i];

                    else if(i%3==2)
                    val &= nums[i];

                    else val |= nums[i];
                }

                ans = max(ans,val);
                return;
                
            }
            nums.push_back(arr[idx]);
            recur(idx+1, arr, nums, ans);
            nums.pop_back();
            recur(idx+1,arr,nums,ans);
        } ;

        int ans= INT_MIN;
        vector<int> nums;
        recur(0, arr, nums, ans);

        cout<<"Number :" <<ans<<endl;

        if(ans%2==0)
        cout<<"Even"<<endl;
        else cout<<"Odd"<<endl;


        





    //  2

    // int n;
    // cin>>n;

    // vector<int> arr(n);
    // for(int &i:arr)
    // cin>>i;

    // function<int(int,vector<int>&, int)> fun = [&](int i,vector<int>&arr, int val)
    // {
    //     if(i==arr.size())
    //     return val;

    //     int curr=INT_MAX;

    //     curr= min(curr, fun(i+1, arr, val + arr[i]));
    //     curr= min(curr, fun(i+1, arr, val - arr[i]));
    //     curr= min(curr, fun(i+1, arr, val * arr[i]));

    //     return curr;
    // };

    // cout<< fun(1,arr,arr[0]);


    



    //  3


//     int n;
//     cin>>n;
//     vector<pair<string ,string>> arr(n);

//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i].first >> arr[i].second; 
//     }

//      sort(arr.begin(), arr.end(), [](const pair<string, string> &a, const pair<string, string> &b) {
//         return stoi(a.first) < stoi(b.first);
//     });

//    vector<pair<string,string>> q;

//    q.push_back(arr[0]);


//     for(int i=1;i<n;i++)
//     {

//         auto &last = q.back();

//         int lastend = stoi(last.second);
//         int curr_st = stoi(arr[i].first);
//         int curr_end= stoi(arr[i].second);

//         if(curr_st <= lastend)
//         {
//             if(curr_end > lastend)
//             last.second = arr[i].second;
//         }
//         else{
//             q.push_back(arr[i]);
//         }


//     }

//     for(const auto &p:q)
//     {
//         cout<<p.first << " "<< p.second << endl;
//         // q.pop();

//     }


 

   


    


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
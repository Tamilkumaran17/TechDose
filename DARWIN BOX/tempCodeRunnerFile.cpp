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
                    val += nums[i];

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
